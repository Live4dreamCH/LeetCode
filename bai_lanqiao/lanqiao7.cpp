#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,k,na,permax=0,num=0,maxlong=0;
    int mn,mnp,sum;
    //int leftbig,perleft,perperleft;//待滑动窗口改进
    //perleft=perperleft=0;
    vector<int> A,maxnum;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>na;
        A.push_back(na);
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            num=1;
            maxnum.push_back(1);
            maxlong=1;
        }
        else if(i<k)
        {
            if(A[i]>=A[i-1])
            {
                num++;
                maxnum.push_back(num);
                maxlong=max(maxlong,num,k);
            }
            else{
                num=1;
                maxnum.push_back(1);
                maxlong=max(maxlong,k);
            }
        }
        else{
            if(A[i]>=A[i-1])
            {
                num++;
                maxnum.push_back(num);
                maxlong=max(maxlong,num,k);
            }
            else{
                num=1;
                maxnum.push_back(1);
                permax=i-1;
                maxlong=max(maxlong,num,k);
            }

            if((permax>=k) && (A[permax-k]<=A[permax+1]))
            {
                mn=maxnum[i];
                mnp=maxnum[permax-k];
                sum=maxnum[i]+k+maxnum[permax-k];
                maxlong=max(maxlong,maxnum[i]+k+maxnum[permax-k]);
            }
            
            else if((permax>=k) &&(A[permax-k]>A[permax+1])) 
            {
                maxlong=max(maxlong,maxnum[i]+k);
            }
            else maxlong=max(maxlong,i+1);
        }

    }
    cout<<maxlong;
    return 0;
}