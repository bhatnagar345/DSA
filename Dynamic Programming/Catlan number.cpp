// catlan number 
 // n = 5;
 // C0 = 1, C1 =1;
 // C5 = C0C4 + C1C3 + C2C2 + C3C2 + C4C1;
 // or C5 = 2nCn/(n+1)




#include<bits/stdc++.h>
using namespace std;
int prefixStrings(int N)
    {
        // Your code goes here
        if(N == 0 || N == 1)return 1;
        long long int c[N+1] ={0};
        c[0] =c[1] =1;
        int mod = 1000000007;
        for(int i=2;i<=N;i++)
        {
           c[i] =0;
           for(int j=0;j<i;j++)
           {
               c[i] += ((c[j]%mod)*(c[i-j-1]%mod))%mod;
           }
        }
        return c[N]%mod;
    }
int main()
{
   cout<<prefixStrings(5)<<endl;
}