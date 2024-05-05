/*Given three arrays sorted in non-decreasing order, print all common elements in these arrays.

Examples:

Input:
ar1[] = {1, 5, 10, 20, 40, 80}
ar2[] = {6, 7, 20, 80, 100}
ar3[] = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20, 80

Input:
ar1[] = {1, 5, 5}
ar2[] = {3, 4, 5, 5, 10}
ar3[] = {5, 5, 10, 20}
Output: 5, 5
*/
#include<iostream>
using namespace std;
void common(int a[],int b[],int c[],int n1,int n2, int n3)
{
    int maxi = max(n1,n2);
    int ar1[maxi] = {0};
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(a[i]==b[j])
        {
            ar1[k++]= a[i];
            i++;
            j++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout<<"after first intersection : "<<endl;
    for(i=0;i<maxi;i++)
    {
        if(ar1[i]!=0)
        {
            cout<<ar1[i]<<" ";
        }
    }
    cout<<endl<<"after the second intersection : "<<endl;
    i=0;
    j=0;
    while(i<n3 && j<k)
    {
        if(c[i]==ar1[j])
        {
            j++;
            i++;
        }
        else if(c[i]< ar1[j])
        {
            i++;
        }
        else
        {
            ar1[j]=0;
            j++;
        }
    }
    for(i=0;i<k;i++)
    {
        if(ar1[i]!= 0)
        {
            cout<<ar1[i]<<" ";
        }
    }
}
int main()
{
    int a[] = {3 ,4 ,2 ,2 ,4};
    int b[] = {3 ,2, 2, 7};
    int c[] = {2,2,3};
    int n1 = sizeof(a)/sizeof(int);
    int n2 = sizeof(b)/sizeof(int);
    int n3 = sizeof(c)/sizeof(int);
    common(a,b,c,n1,n2,n3);
    return 0;
}
