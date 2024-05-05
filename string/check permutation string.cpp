#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "harsh Bhatnagar";
    string t = "Bhatnagar harsh";
    int c[128] = {0} ;
    char st[16];
    if(s.length()!= t.length())
    {
        cout<<"strings are not same "<<endl;
        return 0;
    }
    for(size_t i=0;i<s.length();i++)
    {
        c[(int) s.at(i)]++;
        st[i]= s.at(i);
    }
    for(int i = 0; i< 15; i++)
    {
      c[(int) t.at(i)]--;
      if(c[(int) t.at(i)]<0)
      {
          cout<<"string are not same "<<endl;
          goto app;
      }
    }
    cout<<"string are same "<<endl;
     app:
         {
    for(int i=0;i<15;i++)
    {
        cout<<s.at(i);
    }}
    return 0;
}
