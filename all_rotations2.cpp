#include <bits/stdc++.h>

using namespace std;


void rota(string s,int n)
{
    string l;
    l=s+s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<l[i+j];
        }
        cout<<endl;
    }
}


int main()
{
    string s="abc";
    int n=3;
    rota(s,n);
    return 0;
}
