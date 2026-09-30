#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "--child") {
        cout << "Child executing task ..." << endl;
        Sleep(2000);
        cout << "Child exiting with code 42" << endl;
        return 42;
    }

    char exe[MAX_PATH]; GetModuleFileNameA(NULL, exe, MAX_PATH);
    string command = "\"" + string(exe) + "\" --child";
    vector<char> cmd(command.begin(), command.end()); cmd.push_back('\0');
    STARTUPINFOA si = {}; PROCESS_INFORMATION pi = {}; si.cb = sizeof(si);

    if (!CreateProcessA(NULL, cmd.data(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        cerr << "CreateProcess failed: " << GetLastError() << endl; return 1;
    }
    cout << "Parent waiting for child ..." << endl;
    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD code = 0; GetExitCodeProcess(pi.hProcess, &code);
    cout << "Parent: Child terminated with exit status " << code << endl;
    CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
    return 0;
}
