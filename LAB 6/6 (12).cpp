#include <iostream>
#include <iomanip>
using namespace std;
int main(){double f=0.10;cout<<"Serial fraction f = "<<f<<"\nThreads\tPredicted speedup\n";for(int t: {1,2,4,8})cout<<t<<"\t"<<fixed<<setprecision(3)<<(1.0/(f+(1-f)/t))<<"\n";cout<<"This program prints the Amdahl prediction; actual measurements depend on hardware and workload.\n";}
