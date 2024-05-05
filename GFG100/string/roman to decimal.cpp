#include<bits/stdc++.h>
using namespace std;
int roma(char c)
  {
      if(c == 'I')
        return 1;
      else if(c=='V')
      return 5;
      else if(c=='X')
      return 10;
      else if(c=='L')
      return 50;
      else if(c=='C')
      return 100;
      else if(c=='D')
      return 500;
      else if(c=='M')
      return 1000;
      else
      {
          return -1;
      }
  }
    int romanToDecimal(string str) {
        // code here
        int ans =0;

        for(int i=0;i<str.length();i++)
        {
            int s1 = roma(str[i]);
            if(i+1<str.length())
            {
                int s2 = roma(str[i+1]);
                if(s1 >= s2)
                {
                    ans += s1;
                }
                else{
                    ans = ans + s2 - s1;
                    i = i+1;
                }
            }
            else
            ans += roma(str[i]);
        }
        return ans;
}

int main()
{
    cout<<romanToDecimal("CDMLXV")<<endl<<endl;
    return 0;
}
