#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <functional>
using namespace std;
int main(){cout<<"Process ID (portable placeholder): 1\n";vector<thread>v;for(int i=0;i<4;i++)v.emplace_back([i](){cout<<"Worker "<<i<<" is running in a separate C++ thread.\n";this_thread::sleep_for(chrono::milliseconds(300));});for(auto&t:v)t.join();cout<<"On Windows, inspect threads in Task Manager or Process Explorer; Linux /proc commands are not available on Windows.\n";}
