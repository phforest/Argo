#include "argo/Argo.hpp"
#include "argo/test/utility.hpp"
#include "catch2/catch.hpp"

using namespace argo;

TEST_CASE("Response file parsing", "[ut][argo][responsefile][parsing]")
{
    const auto fn = test::data_file("responsefile_parsing", ".rsp", false);
    ResponseFile rsp;
    REQUIRE(rsp.parse(fn));
    const auto argc = rsp.argc();
    REQUIRE(5 == argc);
    const auto argv = rsp.argv();
    for (auto idx = 0u; idx < argc; ++idx) std::cout << "(idx=" << idx << ", " << argv[idx] << ")" << std::endl;
}

