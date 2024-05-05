#include<bits/stdc++.h>
using namespace std;
string compression(string str)
{
    string newstr = "";
    char prev = str.at(0);
    int coun = 1;
    int n = str.length();
    for(int j =1;j < n; j++)
    {
        if(str.at(j)== prev)
        {
            coun++;
        }
        else{
            newstr += prev;
            newstr += to_string(coun);
            coun = 1;
            prev = str.at(j);
        }
    }
    newstr += prev;
    newstr += to_string(coun);
    int n2 = newstr.length();
    return newstr;
}

int main()
{
    string st = "aabccccaaa";
    string t = compression(st);
    cout<<t<<endl;
    return 0;
}
