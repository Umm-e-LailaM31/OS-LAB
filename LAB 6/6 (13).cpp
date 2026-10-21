#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;using Clock=chrono::steady_clock;
long long sumRange(int lo,int hi){long long s=0;for(int i=lo;i<hi;i++)s+=i;return s;}
double run(int n,int T,long long&sum){vector<long long>p(T);vector<thread>th;int c=(n+T-1)/T;auto a=Clock::now();for(int t=0;t<T;t++)th.emplace_back([&,t](){p[t]=sumRange(t*c,min(n,(t+1)*c));});for(auto&x:th)x.join();sum=0;for(auto x:p)sum+=x;return chrono::duration<double,milli>(Clock::now()-a).count();}
int main(){int n=2000000;long long s;double t1=run(n,1,s);cout<<"Threads\tTime(ms)\tSpeedup\tEfficiency\n";for(int t=1;t<=8;t++){double tm=run(n,t,s);double sp=t1/tm;cout<<t<<"\t"<<fixed<<setprecision(3)<<tm<<"\t"<<sp<<"\t"<<sp/t<<"\n";}}
