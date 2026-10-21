#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>
using namespace std;
int main(){const int K=20;vector<atomic<int>>count(K);for(int i=0;i<K;i++)count[i]=0;
auto carrier=[&](int j){for(int id=j;id<K;id+=2){for(int r=0;r<1000;r++)count[id]++;}};
thread a(carrier,0),b(carrier,1);a.join();b.join();cout<<"M:N simulation: 20 logical user tasks were scheduled over 2 carrier threads.\n";bool ok=true;for(int i=0;i<K;i++)if(count[i]!=1000)ok=false;cout<<"All 20 tasks completed: "<<(ok?"YES":"NO")<<"\n";
unsigned hc=thread::hardware_concurrency();if(hc==0)hc=2;cout<<"Detected hardware concurrency: "<<hc<<"\n";cout<<"Oversubscription concept: compare workloads using "<<hc<<" threads versus "<<4*hc<<" threads on your machine.\n";cout<<"Note: this is a portable scheduling demonstration, not a true M:N runtime.\n";}
