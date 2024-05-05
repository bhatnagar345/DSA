/*
one away = strings should one edit way or or one replace
example
pale, ple == true
pales , pale == true
pale , bale == true
pale , bae == false
*/

#include<bits/stdc++.h>
using namespace std;
bool oneeditreplace(string s1, string s2)
{
    bool forOne = false;
    int n = s1.length();
    for(int i=0;i<n;i++)
    {
        if(s1.at(i)!= s2.at(i))
        {
            if(forOne)
            {
                return false;
            }
            forOne = true;
        }
    }
    return true;
}


bool oneeditinsert(string s1 , string s2)
{
    int index1 =0 ,index2 = 0;
    int n1 = s1.length();
    int n2 = s2.length();
    while(index1 < n1 && index2 < n2)
    {
        if(s1.at(index1) != s2.at(index2))
        {
            if(index1 != index2)
            {
                return false;
            }
             else{
            index1++;
            }
        }
       else{
        index1++;
        index2++;
       }
       }
    return true;
}




bool oneaway(string str1,string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    if(n1 == n2)
    {
        return oneeditreplace(str1,str2);
    }
    if(n1-1 == n2)
    {
        return oneeditinsert(str1,str2);
    }
     if(n1+1 == n2)
    {
        return oneeditinsert(str2,str1);
    }
    return false;
}


int main()
{
    string str1 = "pale";
    string str2 = "bale";
    if(oneaway(str1,str2))
    {
        cout<<"it is one away strings "<<endl;
    }
    else{
        cout<<" it is not one away strings "<<endl;
    }
    return 0;
}
