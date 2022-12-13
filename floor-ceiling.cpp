#include <iostream>

using namespace std;

void f(int a[],int n,int x){
    int c=0,f=0;
    if(x<a[0])
    {f=-1;c=a[0];}
    
    else if(x>a[n-1])
    { f=a[n-1];c=-1;}
    else{
    for(int i=0;i<n;i++)
    {
        if(x<=a[i])
        {
            c=a[i];
            f=a[i-1];
            break;
        }
    }
    }
    cout<<c<<" "<<f<<endl;
}


int main()
{
    int a[]={1,2,8,10,10,12,19};
    int n=7,x=20;
    f(a,n,x);

    return 0;
}
