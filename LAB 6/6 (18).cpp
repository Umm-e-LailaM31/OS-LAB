#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;using Clock=chrono::steady_clock;
void emptyWork(){}
int main(){const int N=1000;auto a=Clock::now();for(int i=0;i<N;i++){thread t(emptyWork);t.join();}double pt=chrono::duration<double,milli>(Clock::now()-a).count();
auto b=Clock::now();volatile int x=0;for(int i=0;i<N*100;i++)x++;double sim=chrono::duration<double,milli>(Clock::now()-b).count();
cout<<"Create + join "<<N<<" C++ threads (ms): "<<pt<<"\nSimple user-space loop baseline (ms): "<<sim<<"\nNote: the second measurement is only a baseline, not a true context switch; portable user-level context switching needs platform-specific APIs.\n";}
