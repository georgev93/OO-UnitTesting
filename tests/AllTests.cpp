#include "CppUTest/CommandLineTestRunner.h"

#ifdef _WIN32
    #pragma clang diagnostic ignored "-Wnonportable-system-include-path"
    #include "windows.h" // Needed for enabling ANSI escape characters on Windows
    #include <cstring>   // Needed for potentially stripping -c arg
#endif

int main(int argc, char** argv) {
// Enable ANSI Escape characters (colors) if compiling in Windows
#ifdef _WIN32
    DWORD dwMode = 0;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    bool allowColor = static_cast<bool>(SetConsoleMode(hOut, dwMode));
    if(!allowColor) {
        for(int i=0; i<argc; ++i) {
            if(strcmp(argv[i], "-c") == 0) {  // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
                for(int j=i; j<argc; j++) {   // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
                    argv[j] = argv[j+1];      // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
                }
                argc--;
            }
        }
    }
#endif

    // Run tests
    return RUN_ALL_TESTS(argc, argv);
}
