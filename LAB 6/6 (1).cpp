#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
long long chunkSum(const vector<long long>& a, int lo, int hi) {
    long long s=0; for(int i=lo;i<hi;i++) s+=a[i]; return s;
}
int main() {
    int n=1000000, T=4;
    vector<long long> a(n); for(int i=0;i<n;i++) a[i]=i+1;
    auto t0=chrono::steady_clock::now();
    long long seq=chunkSum(a,0,n);
    auto t1=chrono::steady_clock::now();
    vector<long long> part(T,0); vector<thread> th;
    int c=(n+T-1)/T;
    for(int t=0;t<T;t++) th.emplace_back([&,t](){part[t]=chunkSum(a,t*c,min(n,(t+1)*c));});
    for(auto& x:th)x.join();
    long long par=0; for(auto x:part)par+=x;
    auto t2=chrono::steady_clock::now();
    cout<<"Sequential sum: "<<seq<<"\nParallel sum: "<<par<<"\nCorrect: "<<(seq==par?"YES":"NO")<<"\n";
    cout<<"Sequential ms: "<<chrono::duration<double,milli>(t1-t0).count()<<"\nParallel ms: "<<chrono::duration<double,milli>(t2-t1).count()<<"\n";
}
