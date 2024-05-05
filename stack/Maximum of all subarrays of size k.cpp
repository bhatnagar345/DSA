#include<bits/stdc++.h>
using namespace std;

void maxsub(int a[],int n ,int k)
{
    deque<int>q(k);
    int i=0;
    for(i;i<k;i++)
    {
        while( !q.empty() && a[q.back()] <= a[i])
            q.pop_back();
        q.push_back(i);
    }
    for(i;i<n;i++)
    {
        cout<<a[q.front()]<<" "<<endl;
        while( !q.empty() && q.front() <= i-k)
            q.pop_front();
        while( !q.empty() && a[q.back()] <= a[i])
            q.pop_back();
        q.push_back(i);
    }
    cout<<a[q.front()]<<" "<<endl;
}

int main()
{
    int a[] ={1 ,3 ,2 ,1 ,4 ,5 ,2 ,3 ,6};
    int n = sizeof(a)/sizeof(int);
    int k=3;
    maxsub(a,n,k);
    return 0;
}