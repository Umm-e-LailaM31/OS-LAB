#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
struct BQueue{queue<long long>q;mutex m;condition_variable full,empty;int cap=8;bool closed=false;
 void put(long long x){unique_lock<mutex>l(m);full.wait(l,[&](){return (int)q.size()<cap;});q.push(x);l.unlock();empty.notify_one();}
 long long get(){unique_lock<mutex>l(m);empty.wait(l,[&](){return !q.empty();});long long x=q.front();q.pop();l.unlock();full.notify_one();return x;}
};
int main(){const int N=10;BQueue q1,q2;long long result=0;
 thread a([&](){for(int i=1;i<=N;i++)q1.put(i);q1.put(-1);});
 thread b([&](){while(true){long long x=q1.get();if(x==-1){q2.put(-1);break;}q2.put(x*x);}});
 thread c([&](){while(true){long long x=q2.get();if(x==-1)break;result+=x;}});
 a.join();b.join();c.join();cout<<"Sum of squares from 1 to "<<N<<": "<<result<<"\nExpected: "<<N*(N+1)*(2*N+1)/6<<"\n";
}
