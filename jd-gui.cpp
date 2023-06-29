#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#pragma comment(linker, "/MERGE:.rdata=.text /MERGE:.data=.text /SECTION:.text,EWR")

#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
    HWND hwnd = FindWindow(L"ConsoleWindowClass", NULL);
    if (hwnd)
    {
        ShowWindow(hwnd, SW_HIDE);
    }

    char* command = new char[1024];
    strcpy_s(command, 512, "call .\\tools\\JadxGui\\jadx-gui.exe ");
    strcat_s(command, 512, argv[1]);
    system(command);

    return 0;
}