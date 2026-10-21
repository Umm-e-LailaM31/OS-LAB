#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
using namespace std;using Clock=chrono::steady_clock;
void taskX(){volatile double s=0;for(int i=1;i<1000000;i++)s+=sqrt((double)i);}
void taskY(){vector<int>v(200000);for(int i=0;i<(int)v.size();i++)v[i]=(i*31)%99991;sort(v.begin(),v.end());}
int main(){auto a=Clock::now();thread t1(taskX),t2(taskY);t1.join();t2.join();cout<<"Two independent sections completed using C++11 threads.\nElapsed time (ms): "<<chrono::duration<double,milli>(Clock::now()-a).count()<<"\nNote: this is a portable equivalent of OpenMP sections; no OpenMP setup is required.\n";}
