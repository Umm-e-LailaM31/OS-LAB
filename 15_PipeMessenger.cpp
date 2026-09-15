#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    HANDLE readPipe, writePipe;

  CreatePipe(&readPipe, &writePipe, nullptr, 0);

    const char message[] = "Hello through the pipe!";
    DWORD written = 0;
    DWORD read = 0;
    char buffer[100] = {};

    WriteFile(
        writePipe,
        message,
        (DWORD)sizeof(message),
        &written,
        nullptr
    );


    ReadFile(
        readPipe,
        buffer,
        sizeof(buffer) - 1,
        &read,
        nullptr
    );

    
    std::cout << buffer << "\n";

    CloseHandle(readPipe);
    CloseHandle(writePipe);

    return 0;
}
