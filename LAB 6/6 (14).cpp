#include <iostream>
#include <iomanip>
using namespace std;
int main(){double p=0.9;cout<<"Parallel fraction p = "<<p<<"\nN\tAmdahl\tGustafson\n";for(int n=1;n<=8;n++){double a=1.0/((1-p)+p/n);double g=n-(1-p)*(n-1);cout<<n<<"\t"<<fixed<<setprecision(3)<<a<<"\t"<<g<<"\n";}cout<<"Amdahl assumes fixed problem size; Gustafson assumes problem size grows with processor count.\n";}
