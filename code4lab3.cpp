#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

// Windows processes are not re-parented like Unix orphan processes.
// This shows a child continuing after the parent program exits.
int main(int argc, char* argv[]) {
    if (argc == 3 && string(argv[1]) == "--child") {
        DWORD originalParent = static_cast<DWORD>(stoul(argv[2]));
        cout << "Child started. Creator PID passed by parent: " << originalParent << endl;
        Sleep(3000);
        cout << "Child is still running after parent program exited. Child PID: "
             << GetCurrentProcessId() << endl;
        return 0;
    }
    char exe[MAX_PATH]; GetModuleFileNameA(NULL, exe, MAX_PATH);
    DWORD parent = GetCurrentProcessId();
    string command = "\"" + string(exe) + "\" --child " + to_string(parent);
    vector<char> cmd(command.begin(), command.end()); cmd.push_back('\0');
    STARTUPINFOA si = {}; PROCESS_INFORMATION pi = {}; si.cb = sizeof(si);
    if (!CreateProcessA(NULL, cmd.data(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        cerr << "CreateProcess failed: " << GetLastError() << endl; return 1;
    }
    cout << "Parent PID: " << parent << " exiting without waiting." << endl;
    CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
    return 0;
}
