#ifndef HEADER_argo_ResponseFile_hpp_INCLUDE_GUARD
#define HEADER_argo_ResponseFile_hpp_INCLUDE_GUARD

#include "argo/details/mss.hpp"
#include "argo/details/string/utility.hpp"
#include <fstream>
#include <vector>

namespace argo {

    class ResponseFile
    {
    public:
        bool parse(const std::string &filename)
        {
            MSS_BEGIN(bool);
            filename_ = filename;
            std::ifstream stream(filename, std::ios_base::in);
            MSS(!stream.fail());
            std::string line;
            while (std::getline(stream, line))
            {
                details::string::ltrim(line);
                if (details::string::starts_with(line, "#")) continue;
                const auto args = details::string::split(line);
                std::copy(RANGE(args), std::back_inserter(argv_));
            }
            MSS_END();
        }
        std::string filename() const { return filename_; }
        int argc() const { return argv_.size(); }
        std::vector<std::string> argv() const { return argv_; }

    private:
        std::string filename_;
        std::vector<std::string> argv_;
    };

}

#endif

