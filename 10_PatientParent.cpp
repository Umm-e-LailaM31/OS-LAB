#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char command[] = "cmd.exe /C ping 127.0.0.1 -n 3 >nul";

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
        WaitForSingleObject(pi.hProcess, INFINITE);

        std::cout << "All done!\n";

        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }

    return 0;
}
