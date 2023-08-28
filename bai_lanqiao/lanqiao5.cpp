#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,x0,y0;
    long double p0,time;
    vector<long double> p,times;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x0>>y0;
        p0=x0*1.0/y0;
        p.push_back(p0);
    }
    times.push_back(1/p[0]);
    for(int i=1;i<n;i++)
    {
        time=1/p[i]+times[i-1]*1/(1-p[i]);
        times.push_back(time);
    }
    cout<<time;
    return 0;
}