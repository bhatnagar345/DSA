#include<bits/stdc++.h>
using namespace std;
void nexrgreat(int a[],int n)
{
    int res[n];
    stack<int>s;
    for(int i=n-1;i>=0;i--)
    {
        if(!s.empty())
        {
            while(!s.empty() && s.top() <= a[i])
                s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[] = {1,2,3,4,5};
    nexrgreat(a,5);
    return 0;
}