#include<bits/stdc++.h>
using namespace std;
int minimum(string s)
{
    map<char,int>m;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        m[s[i]]++;
    }
    bool flag = 1;
    int coun =0;
    for(int i=0;i<n;i++)
    {
        if(flag)
        {
            if(m[s[i]]%2 !=0)
            {
                flag =0;
                m[s[i]] =0;
            }
        }
        else{

            if(m[s[i]]%2 !=0)
            {
                coun++;
                m[s[i]] =0;
            }
        }
    }
    return coun;
}
int main()
{
    string s = "abcdefgh";
    cout<<"the minimum insertion for palindrome : "<<minimum(s)<<endl<<endl;
    return 0;
}
