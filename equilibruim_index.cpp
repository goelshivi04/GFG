#include <bits/stdc++.h>

using namespace std;

int f(int a[],int n)
{
    int e=0;
    for(int i=1;i<n;i++)
    {
        e=i;
        int sum1=0,sum2=0;
        for(int j=0;j<e;j++)
        sum1=sum1+a[i];
        
        for(int k=e+1;k<n;k++)
        sum2=sum2+a[i];
        
        if(sum1==sum2)
        return e;
    }
    return -1;
}

int main()
{
    int a[]={-7,1,5,2,-4,3,0};
    int n=7;
    int ans=f(a,n);
    cout<<ans;
    return 0;
}

