#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
using namespace std; using Clock=chrono::steady_clock;
void taskX(){volatile double s=0;for(int i=1;i<1500000;i++)s+=sqrt((double)i);}
void taskY(){vector<int>v(300000);for(int i=0;i<(int)v.size();i++)v[i]=(i*7919)%100003;sort(v.begin(),v.end());}
int main(){
    auto a=Clock::now();taskX();taskY();auto b=Clock::now();
    auto c=Clock::now();thread x(taskX),y(taskY);x.join();y.join();auto d=Clock::now();
    cout<<"Sequential time (ms): "<<chrono::duration<double,milli>(b-a).count()<<"\nConcurrent time (ms): "<<chrono::duration<double,milli>(d-c).count()<<"\n";
}
