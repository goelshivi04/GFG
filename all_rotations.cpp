#include <bits/stdc++.h>

using namespace std;


void rota(string s,int n)
{
    char temp[n];
    for(int i=0;i<n;i++)
    {
        int j=i;
        int k=0;
        //string temp;
        while(s[j]!='\0')
        {
            temp[k]=s[j];
            j++;
            k++;
        }
        
        j=0;
        while(j<i)
        {
            temp[k]=s[j];
            k++;
            j++;
        }
        for(int i=0;i<n;i++)
        cout<<temp[i];
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
