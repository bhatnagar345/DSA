#include<iostream>
#include<unordered_set>
using namespace std;
void rem(char s[], int n)
{
    int index =0;
    for(int i=0;i<n;i++)
    {
        int j;
        for( j=0;j<i;j++)
        {
            if(s[i] == s[j])
            {
                break;
            }
        }
        if(j==i)
            {
                s[index++] = s[i];
            }
    }
}
int main()
{
    char a[] = "harsh bhatnagar";
    int n = sizeof(a)/sizeof(char);
    rem(a,n);
    cout<<a;
    //unordered_set<char>s(a,a + n-1);
    /*for(auto elm : s)
    {
        cout<<elm;
    }*/
    return 0;
}
