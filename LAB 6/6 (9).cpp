#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;using Clock=chrono::steady_clock;
void busy(int ms){auto end=Clock::now()+chrono::milliseconds(ms);volatile unsigned long long x=0;while(Clock::now()<end)x++;}
double run(vector<int>w){auto a=Clock::now();vector<thread>t;for(int x:w)t.emplace_back(busy,x);for(auto&x:t)x.join();return chrono::duration<double,milli>(Clock::now()-a).count();}
int main(){cout<<"Imbalanced workload time (ms): "<<run({100,400,100,400})<<"\nBalanced workload time (ms): "<<run({250,250,250,250})<<"\nNote: times vary with CPU load and scheduling.\n";}
