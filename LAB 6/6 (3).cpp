#include <iostream>
#include <vector>
#include <thread>
using namespace std;
int main(){
    const int N=100,T=4; vector<vector<long long>>A(N,vector<long long>(N)),B=A,C=A,D=A;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){A[i][j]=i+j+1;B[i][j]=(i==j?1:0);}
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)C[i][j]+=A[i][k]*B[k][j];
    vector<thread> th; int r=(N+T-1)/T;
    for(int t=0;t<T;t++)th.emplace_back([&,t](){for(int i=t*r;i<min(N,(t+1)*r);i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)D[i][j]+=A[i][k]*B[k][j];});
    for(auto&x:th)x.join();
    cout<<"C[0][0] = "<<D[0][0]<<"\nC[10][20] = "<<D[10][20]<<"\nMatrices match: "<<(C==D?"YES":"NO")<<"\n";
}
