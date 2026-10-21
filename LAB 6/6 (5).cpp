#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
int main(){
    const int n=100000,T=4;vector<long long>a(n,2),b(n,3);long long expected=0;
    for(int i=0;i<n;i++)expected+=a[i]*b[i];
    vector<long long>part(T,0);vector<thread>th;int c=(n+T-1)/T;
    for(int t=0;t<T;t++)th.emplace_back([&,t](){for(int i=t*c;i<min(n,(t+1)*c);i++)part[t]+=a[i]*b[i];});
    for(auto&x:th)x.join();
    long long dot=0;mutex m;
    for(int t=0;t<T;t++){lock_guard<mutex> lock(m);dot+=part[t];}
    cout<<"Sequential dot product: "<<expected<<"\nParallel dot product (safe reduction): "<<dot<<"\nCorrect: "<<(expected==dot?"YES":"NO")<<"\n";
    cout<<"Note: shared unsynchronized updates are a data race; this version uses private partial sums and safe reduction.\n";
}
