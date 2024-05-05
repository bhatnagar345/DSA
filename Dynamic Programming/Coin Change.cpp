#include<bits/stdc++.h>
using namespace std;
// std::ios::sync_with_stdio(false);



int counts(int n, int m, int a[],int ma[])
{
    
    if(n ==0) return 0;
    int ans = INT_MAX;
    for(int i=0;i<m;i++)
    {
        if(n-a[i] >=0)
        {
            int sub =0;
            if(ma[n-a[i]] != -1)
            {
                sub = ma[n-a[i]];
            }
            else
            {

             sub =  counts(n-a[i],m,a,ma);

            }
            if(sub!= INT_MAX && sub+1 < ans)
            {
                ans = sub+1;
            }
        }
    }
    ma[n] = ans;
    return ans;

}
int main()
{
    int n = 178;
   int a[] = {1,7,5};
   int m = sizeof(a)/sizeof(int);
   int ma[n+1] = {-1};
   ma[0] =0;
   // 
   for(int i=1;i<=n;i++)
   {
    ma[i] =-1;
   }
   cout<<counts(n,m,a,ma)<<endl;
   // for(int i=1;i<=n;i++)
   // {
   //  cout<<ma[i]<<" ";
   // }
}