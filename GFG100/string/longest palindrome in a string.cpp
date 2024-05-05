#include<bits/stdc++.h>
using namespace std;
 string longestPalin (string &S) {
        // code here

        int n = S.length();
        int len =1;
        int start = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int flag =1;
                for(int k=0; k<(j-i+1)/2; k++)
                {
                    if(S[i+k] != S[j-k])
                     {
                         flag =0;
                         break;
                     }
                }
                if( flag && (j-i+1) >len)
                {
                    start =i;
                    len = j-i+1;
                }
            }
        }
        string ans;
        for(int j=start ; j< start+len;j++)
        {
            ans = ans + S[j];
        }
        return ans;
    }


int main()
{
    string h = "aaaabbaa";
    string l = longestPalin(h);
    cout<<l<<endl;
    return 0;
}

