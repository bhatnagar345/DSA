#include<bits/stdc++.h>
using namespace std;
int nCr(int n, int r){
        // code here
        if(r>n) return 0;
        if((n-r)<r)
        r = n-r;
        int mod = 1000000007;
        int a[r+1];
        memset(a,0,sizeof(a));
        a[0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j= min(i,r);j>0;j--)
            {
                a[j] = (a[j] +a[j-1])%mod;
            }
        }
        return a[r];
    }
int main()
{
   cout<<nCr(3,2)<<endl;
}