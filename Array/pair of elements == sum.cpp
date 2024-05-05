#include<bits/stdc++.h>
using namespace std;
void pairs(int a[],int n, int sum)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        int temp = sum - a[i];
        if(s.find(temp) != s.end())
        {
            cout<<" the pairs of which sum is "<<sum<<" == "<<"{"<<a[i]<<","<<temp<<"}"<<endl;
        }
        s.insert(a[i]);
    }
}
int main()
{
    int a[]={1,4,45,10,6,8};
    int n = 6;
    int sum =16;
    pairs(a,n,sum);
    return 0;
}

