/*Write a function to check whether two given strings are anagram of each other or not.
An anagram of a string is another string that contains the same characters,
only the order of characters can be different.
For example, “abcd” and “dabc” are an anagram of each other
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    string s2;
    cout<<"write down the first string : "<<endl;
    getline(cin,s1);

     cout<<"write down the second string : "<<endl;
     getline(cin,s2);
    int hs[128] = {0};
    if(s1.length() != s2.length())
    {
        cout<<"it is not anagram "<<endl;
    }
    for(int i=0;i<s2.length();i++)
    {
         hs[(int)s2[i]]++;
    }
    for(int i=0;i<s1.length();i++)
    {
        hs[(int) s1[i]]--;
        if(hs[(int) s1[i]] < 0)
        {
            cout<<"there is not anagram "<<endl;
            return 0;
        }
    }
    cout<<"it is anagram "<<endl;
    return 0;
}
