#ifndef HEADER_argo_test_FileComparison_hpp_ALREADY_INCLUDED
#define HEADER_argo_test_FileComparison_hpp_ALREADY_INCLUDED

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace argo { namespace test {

    inline bool streams_are_equal(std::istream &reference, std::istream &test)
    {
        std::istream_iterator<std::string> reference_begin{reference};
        std::istream_iterator<std::string> reference_end{};
        std::istream_iterator<std::string> test_begin{test};
        std::istream_iterator<std::string> test_end{};
#if 0
        //#TODO: Check why this doesn't work in C++11
        return std::equal(reference_begin, reference_end, test_begin, test_end, [](const std::string &lhs, const std::string &rhs){ return lhs == rhs; });
#else
        auto reference_it = reference_begin;
        auto test_it = test_begin;
        while (reference_it != reference_end && test_it != test_end)
        {
            if (*reference_it != *test_it) return false;
            ++reference_it;
            ++test_it;
        }
        return true;
#endif
    }
    inline bool files_are_equal(const std::string &reference, const std::string &test)
    {
        std::ifstream reference_stream;
        reference_stream.open(reference);
        assert(!!reference_stream);
        std::ifstream test_stream;
        test_stream.open(test);
        assert(!!test_stream);
        return streams_are_equal(reference_stream, test_stream);
    }
    inline bool file_and_stream_are_equal(const std::string &reference, std::istream &test)
    {
        std::ifstream reference_stream;
        reference_stream.open(reference);
        if (!reference_stream.good()) std::cerr << "Error: Could not read " << reference << std::endl;
        assert(reference_stream.good());
        return streams_are_equal(reference_stream, test);
    }
    
} }

#endif
