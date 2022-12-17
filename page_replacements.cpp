#include <bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    int pf=0;
    unordered_set<int>s;
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(s.size()<capacity)
        {
            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                pf++;
                q.push(pages[i]);
            }
        }
        else
        {
            if(s.find(pages[i])==s.end())
            {
                int x=q.front();
                q.pop();
                s.erase(x);
                s.insert(pages[i]);
                q.push(pages[i]);
                pf++;
            }
        }
    }
    return pf;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4,2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout << pageFaults(pages, n, capacity);
    return 0;
}
