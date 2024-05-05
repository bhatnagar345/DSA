#include<bits/stdc++.h>
using namespace std;
void nextpalindrome(string &s)
{
    int l = s.length();
    if(l%2 == 0)
    {
        if(s[l/2 -1] > s[l/2])
        {
            int i = l/2 -1;
            int j = l/2;
            while(i>=0 && j<l)
            {
                s[j++] = s[i--];
            }
        }
        if(s[l/2 -1] < s[l/2])
        {
            int i = l/2 -2;
            int j = l/2 +1;
            s[l/2 -1]++;
            s[l/2] = s[l/2 -1];
            while(i>=0 && j<l)
            {
                s[j++] = s[i--];
            }
        }
    }
    else
    {
        int a = l/2 -1;
        int b = l/2 +1;
        while(s[a] == s[b])
        {
            a--;
            b++;
        }
        if(s[a] < s[b] )
        {
            if(s[l/2] == '9')
            {
                s[l/2] = '0';
                int a = l/2 -1;
                while( s[a] == '9')
                {
                    s[a] = '0';
                    a--;
                }
                s[a]++;
            }
            else{
            s[l/2]++;
            }
        }
        int i = l/2 -1;
        int j = l/2 +1;
        while(i>=0 && j<l)
        {
            s[j++] = s[i--];
        }
    }

}


int main()
{
    string h = "2321";
    nextpalindrome(h);
    cout<<h<<endl;
    return 0;
}
