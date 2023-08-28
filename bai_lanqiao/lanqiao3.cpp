#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,num;
    long long int S,sum_he,sum_mi;
    sum_he=sum_mi=0;
    vector<int> a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        a.push_back(num);
    }
    for(int j=0;j<n;j++)
    {
        sum_he=sum_he+a[j];
        sum_mi=sum_mi+a[j]*a[j];
    }
    S=(sum_he*sum_he-sum_mi)/2;
    cout<<S;
    return 0;
}