#include <iostream>
#include <vector>
#include <thread>
#include <climits>
using namespace std;
int main(){
    const int n=100000,T=4; vector<int>a(n);for(int i=0;i<n;i++)a[i]=(i*37)%100003-50000;
    a[45678]=999999;
    int seq=a[0];for(int x:a)if(x>seq)seq=x;
    vector<int> local(T,INT_MIN);vector<thread>th;int c=(n+T-1)/T;
    for(int t=0;t<T;t++)th.emplace_back([&,t](){for(int i=t*c;i<min(n,(t+1)*c);i++)if(a[i]>local[t])local[t]=a[i];});
    for(auto&x:th)x.join();int m=local[0];for(int x:local)if(x>m)m=x;
    cout<<"Sequential maximum: "<<seq<<"\nParallel maximum: "<<m<<"\nCorrect: "<<(seq==m?"YES":"NO")<<"\n";
}
