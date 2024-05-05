#include<bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int r, int k) {
        //code here
        priority_queue<int,vector<int>,greater<int>>q(arr,arr+r);
        int ans =0;
        while(k--)
        {
            ans = q.top();
            q.pop();
        }
        cout<<ans<<endl<<endl;
        return ans;
}
int main()
{
    int a[] = {7 ,10 ,4 ,20 ,15};
    int n = sizeof(a)/sizeof(int);
    kthSmallest(a,n,4);
    return 0;
}
