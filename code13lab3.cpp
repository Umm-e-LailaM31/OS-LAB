#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;
int main() {
    SECURITY_ATTRIBUTES sa = {};
    sa.nLength = sizeof(sa); sa.bInheritHandle = TRUE;
    HANDLE readPipe = NULL, writePipe = NULL;
    if (!CreatePipe(&readPipe, &writePipe, &sa, 0)) {
        cerr << "CreatePipe failed: " << GetLastError() << endl; return 1;
    }
    const char message[] = "Hello Child from kernal Pipe";
    DWORD written = 0, readCount = 0;
    if (!WriteFile(writePipe, message, sizeof(message), &written, NULL)) {
        cerr << "WriteFile failed." << endl; return 1;
    }
    CloseHandle(writePipe);
    char buffer[256] = {};
    if (ReadFile(readPipe, buffer, sizeof(buffer)-1, &readCount, NULL))
        cout << "child read from pipe: " << buffer << endl;
    CloseHandle(readPipe);
}
