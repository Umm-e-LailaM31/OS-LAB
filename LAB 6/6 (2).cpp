#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
using namespace std;
int main() {
    const int n=100000, T=4; vector<double>A(n),B(n),C(n),D(n);
    for(int i=0;i<n;i++){A[i]=i*0.001;B[i]=i*0.002;}
    for(int i=0;i<n;i++) C[i]=A[i]*B[i]+sin(A[i]);
    vector<thread> th; int c=(n+T-1)/T;
    for(int t=0;t<T;t++) th.emplace_back([&,t](){for(int i=t*c;i<min(n,(t+1)*c);i++)D[i]=A[i]*B[i]+sin(A[i]);});
    for(auto&x:th)x.join();
    bool ok=true; for(int i=0;i<n;i++)if(fabs(C[i]-D[i])>1e-10){ok=false;break;}
    cout<<"C[0] = "<<D[0]<<"\nC[1] = "<<D[1]<<"\nC[last] = "<<D[n-1]<<"\nResults match: "<<(ok?"YES":"NO")<<"\n";
}
