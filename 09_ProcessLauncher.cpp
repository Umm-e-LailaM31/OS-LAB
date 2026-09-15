#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char command[] = "cmd.exe /C echo I am the child";

    if (CreateProcessA(
        nullptr,
        command,
        nullptr,
        nullptr,
        FALSE,
        0,
        nullptr,
        nullptr,
        &si,
        &pi
    )) {
        cout << "I am the parent\n";
        WaitForSingleObject(pi.hProcess,INFINITE);

        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    } 

    return 0;
}
