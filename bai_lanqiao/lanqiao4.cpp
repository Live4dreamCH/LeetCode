#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,m,x,a,l,r,maxl;
    vector<int> A,L,R,maxL;
    bool ma;
    cin>>n>>m>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        A.push_back(a);
    }
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        L.push_back(l);
        R.push_back(r);
    }
    maxL.push_back(-1);
    for(int i=1;i<n;i++)
    {
        maxL.push_back(-1);
        for(int j=0;j<i;j++)
        {
            if((A[i] xor A[j])==x)
            {
                maxL[i]=j;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        ma=false;
        for(int j=L[i];j<=R[i]-1;j++)
        {
            if(maxL[j]>=L[i]-1)
            {
                ma=true;
                cout<<"yes"<<endl;
                break;
            }
        }
        if(ma==false)cout<<"no"<<endl;
    }

    return 0;
}