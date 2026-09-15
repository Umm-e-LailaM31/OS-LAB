#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    const char* user = getenv("USERNAME");

    if (user != nullptr)
        std::cout << "Current user is: " << user << "\n";
    return 0;
}
