#include <iostream>
#include <windows.h>

int main() {
    char* page = static_cast<char*>(VirtualAlloc(
        nullptr, 4096, MEM_COMMIT, PAGE_READWRITE));

    if (!page) return 1;

    page[0] = 'A';

    DWORD oldProtect = 0;
    if (!VirtualProtect(page, 4096, PAGE_READONLY, &oldProtect)) {
        VirtualFree(page, 0, MEM_RELEASE);
        return 1;
    }

    __try {
        page[0] = 'B';
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        std::cout << "Hardware memory protection trap caught!\n";
    }

    VirtualFree(page, 0, MEM_RELEASE);
    return 0;
}
