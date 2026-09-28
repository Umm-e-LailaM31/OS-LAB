#include <iostream>
#include <windows.h>

int main() {
    HANDLE hFile = CreateFileA(
        "async.bin", GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS,
        FILE_FLAG_OVERLAPPED, nullptr);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "CreateFile failed. Error: " << GetLastError() << "\n";
        return 1;
    }

    OVERLAPPED ol{};
    ol.hEvent = CreateEventA(nullptr, TRUE, FALSE, nullptr);
    if (!ol.hEvent) {
        CloseHandle(hFile);
        return 1;
    }

    char buffer[1024] = "Asynchronous file write data packet.";
    DWORD bytesWritten = 0;

    BOOL ok = WriteFile(hFile, buffer, sizeof(buffer), &bytesWritten, &ol);
    if (!ok && GetLastError() != ERROR_IO_PENDING) {
        std::cerr << "WriteFile failed. Error: " << GetLastError() << "\n";
        CloseHandle(ol.hEvent);
        CloseHandle(hFile);
        return 1;
    }

    std::cout << "I/O initiated. Doing computation in parallel...\n";

    WaitForSingleObject(ol.hEvent, INFINITE);
    DWORD transferred = 0;
    if (!GetOverlappedResult(hFile, &ol, &transferred, FALSE)) {
        std::cerr << "GetOverlappedResult failed. Error: " << GetLastError() << "\n";
        CloseHandle(ol.hEvent);
        CloseHandle(hFile);
        return 1;
    }

    std::cout << "Asynchronous write fully committed.\n";
    CloseHandle(ol.hEvent);
    CloseHandle(hFile);
    return 0;
}
