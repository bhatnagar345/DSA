/*Write an efficient C++ function that takes two strings as arguments and removes
the characters from first string which are present in second string (mask string).
*/
#include<iostream>
using namespace std;
void *remov(char first[],int m,char a[],int n)
{
    int has[128] = {0};
    for(int i =0;i<n;i++)
    {
        has[a[i]]++;
    }
    int index =0;
    for(int i=0;i<m;i++)
    {
        if(has[first[i]])
        {
        }
        else{
            first[index++] = first[i];
        }
    }
        first[index] = NULL;

    cout<<first<<endl;
}
int main()
{
    char first[] = "harsh bhatnagar";
    int m = sizeof(first)/sizeof(char);
    char a[] = "marks";
    int n = sizeof(a)/sizeof(char);
    remov(first,m,a,n);
    return 0;
}
