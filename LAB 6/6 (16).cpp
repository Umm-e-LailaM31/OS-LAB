#include <iostream>
#include <vector>
using namespace std;
int main(){const int K=3,ROUNDS=3;vector<int>count(K,0);cout<<"Cooperative round-robin user-thread simulation\n";for(int r=0;r<ROUNDS;r++)for(int id=0;id<K;id++){count[id]++;cout<<"User thread "<<id<<" ran; simulated process ID = 1; step = "<<count[id]<<"\n";}cout<<"All simulated user threads made progress.\nNote: portable simulation for Dev-C++; it does not create real OS contexts like POSIX ucontext.\n";}
