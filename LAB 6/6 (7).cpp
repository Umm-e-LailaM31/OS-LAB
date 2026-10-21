#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
int main(){
    const int K=5,N=12;queue<int>q;mutex m;condition_variable notFull,notEmpty;bool done=false;long long sum=0;
    thread producer([&](){for(int i=1;i<=N;i++){unique_lock<mutex>lk(m);notFull.wait(lk,[&](){return (int)q.size()<K;});q.push(i);cout<<"Produced "<<i<<"\n";lk.unlock();notEmpty.notify_one();}
        {lock_guard<mutex>lk(m);done=true;}notEmpty.notify_one();});
    thread consumer([&](){while(true){unique_lock<mutex>lk(m);notEmpty.wait(lk,[&](){return !q.empty()||done;});if(q.empty()&&done)break;int x=q.front();q.pop();lk.unlock();notFull.notify_one();sum+=x;cout<<"Consumed "<<x<<"\n";}});
    producer.join();consumer.join();cout<<"Sum consumed: "<<sum<<"\nExpected sum: "<<N*(N+1)/2<<"\n";
}
