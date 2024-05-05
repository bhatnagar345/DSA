#include<bits/stdc++.h>
using namespace std;
 bool ispalindrome(string s)
{
    int n = s.length();
    int tab[128]={0};
    int coun = 0;
    for(int i=0;i<n;i++)
    {
        if(s.at(i)!=' ')
        {
        tab[s.at(i)]++;
        if(tab[s.at(i)]%2 == 0  )
        {
            coun--;
        }
        else
        {
            coun++;
        }
        }
    }
    if(coun == 1 || coun == 0)
    {
        return true;
    }
    else{
        return false;
    }
}
int ppalindrome(string s)
{
    int l = 0;
    int h = s.length() -1;
    while(l<h)
    {
        if(s[l++] != s[h--])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string h = "abba";
    if(ppalindrome(h))
    {
        cout<<"it is palindromic permutation "<<endl;
    }
    else
    {
        cout<<"it is not palindromic permutation "<<endl;
    }
    return 0;
}
