#include <iostream>
#include <iomanip>
using namespace std;
int main(){double fTrue=0.10;cout<<"N\tMeasured-like speedup\tEstimated serial fraction\n";for(int n: {2,4,8}){double s=1.0/(fTrue+(1-fTrue)/n);double f=(1.0/s-1.0/n)/(1.0-1.0/n);cout<<n<<"\t"<<fixed<<setprecision(3)<<s<<"\t\t"<<f<<"\n";}cout<<"In real experiments, use measured speedups; estimates may vary due to overhead.\n";}
