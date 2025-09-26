#include "../Include/Server.hpp"
#include "../Include/DictionarySearchHandler.hpp"
#include "../Include/ExitHandler.hpp"





#define POSIX_SLEEP_DURATION 1
#define WIN32_SLEEP_DURATION 1000

volatile bool exitNow = false;


int main(const int argc,
         const char* const* argv)
{
    mg_init_library(CIVIT_WEB_INIT_BITMASK);


    std::vector<std::string> cppOptions;



    cppOptions.emplace_back("document_root");
    cppOptions.emplace_back(UI_ROOT);
    cppOptions.emplace_back("listening_ports");
    cppOptions.emplace_back(PORT_NUMBER);
    cppOptions.emplace_back("enable_auth_domain_check");
    cppOptions.emplace_back("no");
    cppOptions.emplace_back("authentication_domain");
    cppOptions.emplace_back("192.168.0.69:12345");



    CivetServer server(cppOptions);
    DictionarySearchHandler dictionaryHandler;
    ExitHandler exitHandler;


    server.addHandler(DICTIONARY_SEARCH_URI, dictionaryHandler);
    server.addHandler(EXIT_URI, exitHandler);



    while (!exitNow)
    {
#ifdef _WIN32
        Sleep(WIN32_SLEEP_DURATION);
#else
        sleep(POSIX_SLEEP_DURATION);
#endif
    }


    mg_exit_library();
}