//longest subarray with same difference...
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {10,7,4,6,8,10,11};
    int n = 7;
    int curr = 2;
    int prev = a[1] -a[0];
    int j =2;
    int ans =2;
    for(j=2;j<n;j++)
    {
        if(prev == a[j]-a[j-1])
        {
            curr++;
        }
        else{
            prev = a[j]-a[j-1];
            curr =2;
        }
        ans = max(ans,curr);
    }
    cout<<"longest Airthmatic Progression subarray : "<<ans<<endl;
}
