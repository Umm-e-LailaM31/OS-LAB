#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

// Windows equivalent demonstration: launch a separate command interpreter to list files.
int main() {
    STARTUPINFOA si = {}; PROCESS_INFORMATION pi = {}; si.cb = sizeof(si);
    char command[] = "cmd.exe /c dir";
    cout << "Parent launching cmd.exe to execute dir..." << endl;
    if (!CreateProcessA(NULL, command, NULL, NULL, FALSE, CREATE_NEW_CONSOLE,
                        NULL, NULL, &si, &pi)) {
        cerr << "CreateProcess failed: " << GetLastError() << endl; return 1;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    cout << "Parent observed command process completion." << endl;
    CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
    return 0;
}
