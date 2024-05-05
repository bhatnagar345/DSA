#include<bits/stdc++.h>
#include<string>
using namespace std;
bool uniqu(string str)
{
    int n = str.length();
    if(str.length() >128)
    {
        return false;
    }
    int c[128] = {0};
    for(int i=0;i<n;i++)
    {
        int val = str.at(i);
        if(c[val]>0)
        {
            return false;
        }
        c[val]++;
    }
    return true;
}
int main()
{
    string st = "absd vghjk";
    if(uniqu(st))
    {
        cout<<"it is unique string "<<endl;
    }
    else{
        cout<<"it is not unique string "<<endl;
    }
    return 0;
}
