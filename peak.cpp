#include <iostream>

using namespace std;

int f(int a[],int n){
    
    if(a[0]>a[1])
    return a[0];
    
    if(a[n-1]>a[n-2])
    return a[n-1];
    
    for(int i=1;i<n-1;i++)
        if( (a[i]>a[i-1]) && (a[i]>a[i+1]) )
            return a[i];
}


int main()
{
    int a[]={10,90,15,2,23,20,67};
    int n=7;
    int ans=f(a,n);
    cout<<ans<<endl;
    return 0;
}
