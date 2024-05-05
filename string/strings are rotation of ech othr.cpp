/*Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/
#include<iostream>
using namespace std;
void rotation(char a[], char b[],int n, int m)
{
   if(n != m)
   {
       cout<<"there is no rotation "<<endl;
   }
   int l = m+n;
   char temp[l];
   int j=0;
   for(int i=0;i<n;i++)
   {
       temp[j++] = a[i];
   }
   int k =j-1;
   for(int i=0;i<m;i++)
   {
       temp[k++] = b[i];
   }
   for(int i=0;i<l;i++)
   {
     cout<<temp[i];
   }

}
int main()
{
    char a[] = "ABCDE";
    char b[] = "EDCBA";
    int n = sizeof(a)/sizeof(char);
    int m = sizeof(b)/sizeof(char);
    rotation(a,b,n,m);
    return 0;
}
