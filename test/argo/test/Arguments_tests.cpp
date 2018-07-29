#include "argo/Argo.hpp"
#include "argo/test/FileComparison.hpp"
#include "argo/test/utility.hpp"
#include "catch2/catch.hpp"
#include <iostream>
#include <vector>

using namespace argo;

namespace {

    template<typename T>
    struct POD { T value; };

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const POD<T>& pod)
    {
        os << "pod.value: " << pod.value << std::endl;
        return os;
    }
    template<typename T>
    std::ostream &operator<<(std::ostream &os, const POD<std::vector<T>>& pod)
    {
        os << "pod.value: ";
        std::copy(RANGE(pod.value), std::ostream_iterator<T>(std::cout, " "));
        os << std::endl;
        return os;
    }

    struct VerifyPOD
    {
        Arguments &args;
        handler::Option &option;
        const RawList &raw_args;

        explicit VerifyPOD(Arguments &args, handler::Option &option, const RawList &raw_args):
            args(args),
            option(option),
            raw_args(raw_args)
        {}

        template<typename POD>
        bool operator()(const POD pod)
        {
            MSS_BEGIN(bool);
            MSS(args.add(std::move(option)));
            const auto &result = args.parse(raw_args);
            MSS(result.success, std::cerr << result.message << std::endl;);
            std::cout << pod << std::endl;
            MSS_END();
        }
    };


};

TEST_CASE("Arguments: help", "[ut][argo][help]")
{
    Configuration config;
    config.program.name.brief = "awesome-app";
    config.program.name.extended = "My Awesome App";
    config.program.description.brief = "Brief description of this app.";
    config.program.description.extended = "Every app can have both a short and long description. Whereas the short description should give the most basic information, this section can go into more detail. In fact, I'm just rambling here to get some line wrapping action going.";
    config.program.version.major = 1;
    config.program.version.githash = "sd45f7";
    Arguments args{config};
    std::string expected_fn;
    SECTION("Basic")
    {
        {
            handler::Option option{"--foo"};
            option.help("This is a long description for the option foo which really only serves the purpose to have enough content so that we need multiple lines in the help output. I guess this is enough now.");
            option.required();
            REQUIRE(args.add(option));
        }
        {
            handler::Option option{"--bar"};
            option.help("A relatively short description. Especially compared to --foo");
            REQUIRE(args.add(option));
        }
        expected_fn = test::data_file("help_basic", ".txt");
    }
    SECTION("Advanced")
    {
        {
            handler::Option option{"--input"};
            option.nargs("+");
            option.required();
            REQUIRE(args.add(option));
        }
        {
            handler::Option option{"--output"};
            option.required();
            REQUIRE(args.add(option));
        }
        {
            handler::group::Inclusive group{"Algorithm"};
            {
                handler::group::Exclusive subgroup{"Foo Algorithm"};
                {
                    handler::Option option{"--foo"};
                    option.toggle();
                    REQUIRE(subgroup.add(option));
                }
                {
                    handler::Option option{"--foo-param"};
                    REQUIRE(subgroup.add(option));
                }
                REQUIRE(group.add(subgroup));
            }
            group.required();
            {
                handler::group::Exclusive subgroup{"Bar Algorithm"};
                {
                    handler::Option option{"--bar"};
                    option.toggle();
                    REQUIRE(subgroup.add(option));
                }
                {
                    handler::Option option{"--bar-param"};
                    REQUIRE(subgroup.add(option));
                }
                REQUIRE(group.add(subgroup));
            }
            REQUIRE(args.add(group));
        }
        expected_fn = test::data_file("help_advanced", ".txt");
    }
    //Via parsing
    {
        RawList raw_args = {"-h"};
        const auto result = args.parse(raw_args);
        REQUIRE(result.success);
    }
    //Via printing
    {
        std::stringstream actual;
        args.print_help(actual);
        REQUIRE(!!test::file_and_stream_are_equal(expected_fn, actual));
        //#NOTE: use the following code to generate the reference files
        //std::ofstream of(expected_fn, std::ios::out);
        //of << actual.str();
    }
}

TEST_CASE("Arguments: required", "[ut][argo][required]")
{
    Arguments args{};
    RawList raw_args;
    std::string expected;
    handler::Option option{"-f", "--foo"};
    option.required();
    REQUIRE(args.add(option));
    const auto result = args.parse(raw_args);
    REQUIRE_FALSE(result.success);
    args.print_help(std::cout);
}

TEST_CASE("Arguments: type conversion", "[ut][argo][action][store]")
{
    Arguments args{};
    RawList raw_args;
    std::string expected;
    handler::Option option{"-f", "--foo"};

    SECTION("std::string")
    {
        using type = std::string;

        SECTION("Single element")
        {
            POD<type> pod;
            option.action(action::Callback<type>{[&pod](const type &value){ pod.value = value; return true; }});
            raw_args = {"-f", "test"};
            VerifyPOD verify{args, option, raw_args};
            REQUIRE(verify(pod));
            REQUIRE("test" == pod.value);
        }
        SECTION("Vector")
        {
            POD<std::vector<type>> pod;
            option.action(action::Callback<type>{[&pod](const type &value){ pod.value.push_back(value); return true; }});
            option.nargs("+");
            raw_args = {"-f", "one", "two", "three", "four", "five"};
            VerifyPOD verify{args, option, raw_args};
            REQUIRE(verify(pod));
            REQUIRE(std::vector<type>({"one", "two", "three", "four", "five"}) == pod.value);
        }
    }
    SECTION("unsigned int")
    {
        using type = unsigned int;

        SECTION("Single element")
        {
            POD<type> pod;
            option.action(action::store(pod.value));
            raw_args = {"-f", "1"};
            VerifyPOD verify{args, option, raw_args};
            REQUIRE(verify(pod));
            REQUIRE(1 == pod.value);
        }
        SECTION("Vector")
        {
            POD<std::vector<type>> pod;
            option.action(action::store(pod.value));
            option.nargs("+");
            raw_args = {"-f", "1", "2", "3", "4", "5"};
            VerifyPOD verify{args, option, raw_args};
            REQUIRE(verify(pod));
            REQUIRE(std::vector<type>({1, 2, 3, 4, 5}) == pod.value);
        }
    }
    SECTION("unsigned int")
    {
        using type = float;

        SECTION("Single element")
        {
            POD<type> pod;
            option.action(action::store(pod.value));
            raw_args = {"-f", "1.2"};
            VerifyPOD verify{args, option, raw_args};
            REQUIRE(verify(pod));
            REQUIRE(1.2f == pod.value);
        }
        SECTION("Vector")
        {
            POD<std::vector<type>> pod;
            option.action(action::store(pod.value));
            option.nargs("*");
            raw_args = {"-f", "1.2", "2.3", "3.4", "4.5", "5.6"};
            VerifyPOD verify{args, option, raw_args};
            REQUIRE(verify(pod));
            REQUIRE(std::vector<type>({1.2f, 2.3f, 3.4f, 4.5f, 5.6f}) == pod.value);
        }
    }
}

TEST_CASE("Arguments: number of arguments", "[ut][argo][nargs]")
{
    Arguments args{};
    RawList raw_args;
    std::string expected;
    handler::Option option{"-f", "--foo"};

    SECTION("Fixed number")
    {
        option.action(action::print());
        option.nargs(2);
        REQUIRE(args.add(std::move(option)));
        SECTION("Correct")
        {
            raw_args = {"-f", "a", "b"};
            expected = R"({
  success: 1,
  message: "",
  nr_options: "1",
  nr_args: "2"
})";
        }
        SECTION("Incorrect")
        {
            raw_args = {"-f", "a", "b", "c"};
            expected = R"({
  success: 0,
  message: "Option '--foo (-f)' expects 2 arguments: unexpected 'c'",
  nr_options: "1",
  nr_args: "2"
})";
        }
    }
    SECTION("One or more")
    {
        option.action(action::print());
        option.nargs("+");
        REQUIRE(args.add(std::move(option)));
        raw_args = {"-f", "a", "b"};
        expected = R"({
  success: 1,
  message: "",
  nr_options: "1",
  nr_args: "2"
})";
    }
    SECTION("Zero or more")
    {
        option.action(action::print());
        option.nargs("*");
        REQUIRE(args.add(std::move(option)));
        raw_args = {"-f", "a", "b"};
        expected = R"({
  success: 1,
  message: "",
  nr_options: "1",
  nr_args: "2"
})";
    }

    const auto result = args.parse(raw_args);
    std::ostringstream os;
    os << result;
    REQUIRE(expected == os.str());
}

TEST_CASE("Arguments: groups", "[ut][argo][groups]")
{
    Arguments args{};
    RawList raw_args;
    std::string expected;
    SECTION("Plain")
    {
        handler::group::Plain group{"my group"};
        handler::Option option{"-f", "--foo"};
        REQUIRE(option.is_valid());
        REQUIRE(group.add(option));
        REQUIRE(group.is_valid());
        REQUIRE(args.add(group));
        raw_args = {"-f", "1"};
        expected = R"({
  success: 1,
  message: "",
  nr_options: "1",
  nr_args: "1"
})";
    }
    SECTION("Exclusive")
    {
        handler::group::Exclusive group{"my group"};
        {
            handler::Option option{"--foo"};
            REQUIRE(group.add(option));
        }
        {
            handler::Option option{"--bar"};
            REQUIRE(group.add(option));
        }
        REQUIRE(args.add(group));
        raw_args = {"-f", "1", "-b", "2"};
        expected = R"({
  success: 0,
  message: "Previously used option '--foo' excludes use of '-b'",
  nr_options: "1",
  nr_args: "1"
})";
    }
    SECTION("Inclusive")
    {
        handler::group::Inclusive group{"my group"};
        {
            handler::Option option{"--foo"};
            REQUIRE(group.add(option));
        }
        {
            handler::Option option{"--bar"};
            REQUIRE(group.add(option));
        }
        REQUIRE(args.add(group));
        raw_args = {"-f", "1"};
        expected = R"({
  success: 0,
  message: "Missing option '--bar'",
  nr_options: "1",
  nr_args: "1"
})";
    }
    SECTION("Complex: inclusive group containing two exclusive groups")
    {
        handler::group::Inclusive group{"group-inc"};
        {
            handler::group::Exclusive subgroup{"group-exc-1"};
            {
                handler::Option option{"--foo"};
                REQUIRE(subgroup.add(option));
            }
            {
                handler::Option option{"--bar"};
                REQUIRE(subgroup.add(option));
            }
            REQUIRE(group.add(subgroup));
        }
        {
            handler::group::Exclusive subgroup{"group-exc-2"};
            {
                handler::Option option{"--foofoo"};
                REQUIRE(subgroup.add(option));
            }
            {
                handler::Option option{"--barbar"};
                REQUIRE(subgroup.add(option));
            }
            REQUIRE(group.add(subgroup));
        }
        REQUIRE(args.add(group));
        SECTION("Correct")
        {
            raw_args = {"--foo", "1", "--barbar", "2"};
            expected = R"({
  success: 1,
  message: "",
  nr_options: "2",
  nr_args: "2"
})";
        }
        SECTION("Incorrect")
        {
            raw_args = {"--foo", "1"};
            expected = R"({
  success: 0,
  message: "Missing an option from group 'group-exc-2'",
  nr_options: "1",
  nr_args: "1"
})";
        }
    }

    const auto result = args.parse(raw_args);
    std::ostringstream os;
    os << result;
    REQUIRE(expected == os.str());
}

TEST_CASE("Arguments: unknown options", "[ut][argo][unknown]")
{
    Arguments args{};
    handler::Option option{"--foo"};
    REQUIRE(args.add(option));
    RawList raw_args;
    std::string expected;
    SECTION("Misspelled existing option")
    {
        raw_args = {"-foo", "1"};
        expected = R"({
  success: 0,
  message: "Unknown option '-foo': did you mean '--foo'?",
  nr_options: "0",
  nr_args: "0"
})";
    }
    SECTION("Misspelled unknown option")
    {
        raw_args = {"-bar", "1"};
        expected = R"({
  success: 0,
  message: "Unknown option '-bar': invalid shorthand or longhand notation",
  nr_options: "0",
  nr_args: "0"
})";
    }
    const auto result = args.parse(raw_args);
    std::ostringstream os;
    os << result;
    REQUIRE(expected == os.str());
}

TEST_CASE("Arguments: option guessing", "[ut][argo][option][guessing]")
{
    Arguments args{};
    RawList raw_args;
    std::string expected;
    std::string actual;
    auto set_actual = [&actual](const std::string &origin, const std::string &name){ actual = origin; return true; };
    auto add_option = [&args, &set_actual](const std::string &name)
    {
        handler::Option option{name};
        option.toggle();
        //Must use an intermediate std::function with MSVC
        std::function<bool(const std::string &)> set_actual_f = std::bind(set_actual, name, std::placeholders::_1);
        option.action(action::callback(set_actual_f));
        return args.add(option);
    };
    SECTION("Unambiguous")
    {
        REQUIRE(add_option("--foo"));
        REQUIRE(add_option("-f"));
        SECTION("--foo")
        {
            raw_args = {"--foo"};
        }
        SECTION("-f")
        {
            raw_args = {"-f"};
        }
        expected = raw_args[0];
    }
    SECTION("Ambiguous")
    {
        REQUIRE(add_option("--foo"));
        REQUIRE(add_option("-f"));
        raw_args = {"-f"};
        expected = raw_args[0];
    }
    SECTION("Guessing")
    {
        REQUIRE(add_option("--foo"));
        raw_args = {"-f"};
        expected = "--foo";
    }
    const auto result = args.parse(raw_args);
    REQUIRE(result.success);
    REQUIRE(expected == actual);
}

TEST_CASE("Arguments: response file integration", "[ut][argo][responsefile][integration]")
{
    Arguments args{};
    RawList raw_args;
    bool called = false;
    {
        const auto fn = test::data_file("responsefile_integration", ".rsp", false);
        raw_args.push_back("@" + fn);
    }
    {
        handler::Option option{"--foo"};
        option.toggle();
        option.action(action::callback([&called](){ called = true; return true; }));
        REQUIRE(args.add(option));
    }

    const auto result = args.parse(raw_args);
    REQUIRE(result.success);
    REQUIRE(!!called);
}

TEST_CASE("Arguments: inheritance", "[ut][argo][responsefile][inheritance]")
{
    Arguments one{};
    Arguments two{};
    RawList raw_args;
    std::string expected;
    std::string actual;
    auto add_option = [&actual](Arguments &args, const std::string &name, const std::string &output)
    {
        handler::Option option{name};
        option.toggle();
        option.action(action::callback([&actual, output](){ actual += output; return true; }));
        return args.add(option);
    };
    SECTION("Disjunct")
    {
        REQUIRE(add_option(one, "--foo", "[foo]"));
        REQUIRE(add_option(two, "--bar", "[bar]"));
        REQUIRE(two.add(one));
        raw_args = {"--foo", "--bar"};
        expected = "[foo][bar]";
    }
    SECTION("Overlap")
    {
        REQUIRE(add_option(one, "--foo", "[one:foo]"));
        REQUIRE(add_option(two, "--foo", "[two:foo]"));
        REQUIRE(add_option(two, "--bar", "[bar]"));
        bool replace;
        SECTION("Replace")
        {
            replace = true;
            expected = "[one:foo][bar]";
        }
        SECTION("Don't replace")
        {
            replace = false;
            expected = "[two:foo][bar]";
        }
        REQUIRE(two.add(one, replace));
        raw_args = {"--foo", "--bar"};
    }

    const auto result = two.parse(raw_args);
    REQUIRE(result.success);
    REQUIRE(expected == actual);
}
