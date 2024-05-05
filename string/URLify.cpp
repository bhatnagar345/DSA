//fill the space with %20 in a string
#include<bits/stdc++.h>
using namespace std;
class URIlyf
{
private :
    int space =0;
public:
    int index;
    void urlify(string str,int u)
    {
      int f = str.length();
      int  n= str.length();
      int i;
      for( i=0;i<u;i++)
    {
        if(str.at(i)==' ')
        {
            space++;
        }
    }
     index = u + space*2 ;
    if(u<f)
    {
        str.at(u)='/0';
    }
    for( i=u-1;i>=0;i--)
    {
        if(str.at(i) == ' ')
        {
            str.at(index -1)='0';
             str.at(index -2)='2';
              str.at(index -3)='%';
              index = index -3;
        }
        else
        {
            str.at(index-1)= str.at(i);
            index--;
        }
    }
    cout<<str;
}
};
int main()
{
    string s = "harsh bhat   ";
    int u =10;
    URIlyf f;
    f.urlify(s,u);
     return 0;
}
