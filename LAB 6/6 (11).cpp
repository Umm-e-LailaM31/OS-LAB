#include <iostream>
#include <iomanip>
using namespace std;
int main(){double p=0.9;cout<<"Parallel fraction p = "<<p<<"\nThreads\tTheoretical speedup\n";for(int n=1;n<=16;n++)cout<<n<<"\t"<<fixed<<setprecision(3)<<(1.0/((1-p)+p/n))<<"\n";}
