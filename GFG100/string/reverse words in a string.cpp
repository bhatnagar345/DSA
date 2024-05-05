/*Input: s = “geeks quiz practice code”
Output: s = “code practice quiz geeks”

Input: s = “getting good at coding needs a lot of practice”
Output: s = “practice of lot a needs coding at good getting”
*/
#include<bits/stdc++.h>
using namespace std;
void reversword(string s)
{
    string str = "";
    vector<string>vec;
    for(int i =0; i< s.length();i++)
    {
        if(s.at(i)=='.')
        {
            vec.push_back(str);
            vec.push_back(".");
            str = "";
        }
        else{
            str += s[i];
        }
    }
    vec.push_back(str);
    cout<<"after reversing the string : "<<endl;
    for(int i = vec.size()-1;i>0;i--)
    {
     cout<<vec[i];
    }
    cout<<vec[0]<<endl;
}
int main()
{
    string s ;
    cout<<"write down the string : "<<endl;
    getline(cin,s);
    int n = s.size();
    reversword(s);
    return 0;
}
