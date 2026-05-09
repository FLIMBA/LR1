#include <console.h>
#include <cstdlib>

void clear_console() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}