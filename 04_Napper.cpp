#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    std::cout << "Going to sleep...\n";

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "Waking up!\n";
    return 0;
}
