#include "argo/Argo.hpp"
#include <iostream>

using namespace argo;

struct AppConfiguration
{ 
    std::vector< std::string >      input_files;
    std::string                     output_files;
    bool            debug   = false;
};

#define ARGO_OPTION( opt , hlp , var ) argo::handler::Option( opt ).help(hlp).action( argo::action::store( var ))

#define APP_VERSION_MAJOR 1
#define APP_VERSION_MINOR 2
#define APP_VERSION_PATCH 3

int main(int argc, char *argv[])
{
    AppConfiguration config;
    argo::Configuration argo_config;

    argo_config.program.name      = { "app" , "Argo Test App" };
    argo_config.program.version   = { APP_VERSION_MAJOR, APP_VERSION_MINOR , APP_VERSION_PATCH };

    argo::Arguments args( argo_config );

    args.add( ARGO_OPTION( "--input-files","specify the input files to process."    ,   config.input_files ).nargs("+"));
    args.add( ARGO_OPTION( "--output-file","specify the output filename."           ,   config.output_files ).required());
    args.add( ARGO_OPTION( "--debug","print debug messages."                        ,   config.debug ).toggle());

    const auto result = args.parse(argc, argv);
    if (!result.success)
    {
        std::cerr << "Error: " << result.message << std::endl;
        return 1;
    }
}
