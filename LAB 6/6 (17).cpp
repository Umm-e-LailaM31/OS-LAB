#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;
int main(){cout<<"Model A: cooperative user threads\n";cout<<"Thread A enters a blocking read; without a scheduler/yield, Thread B cannot run in a single-carrier cooperative model.\n";
cout<<"\nModel B: kernel threads (C++ threads)\n";atomic<bool>done(false);thread b([&](){for(int i=1;i<=5;i++){cout<<"Counter thread progress: "<<i<<"\n";this_thread::sleep_for(chrono::milliseconds(100));}done=true;});cout<<"Main thread represents a thread blocked on input, while the counter thread continues.\n";b.join();cout<<"Demonstration complete.\n";}
