/*Given n non-negative integers representing an elevation map where the
width of each bar is 1, compute how much water it is able to trap after
raining.

Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
*/


#include<bits/stdc++.h>
using namespace std;
void left(int a[],int n)
{
    int maxi=0,temp;                   
    for(int i=0;i<n;i++)
    {
        temp = a[i];
        a[i]=maxi;
        if(maxi<temp)
        {
            maxi = temp;
        }
    }
}
void right(int a[],int n)
{
    int maxi=0,temp;
    for(int i=n-1;i>=0;i--)
    {
        temp = a[i];
        a[i]=maxi;
        if(maxi<temp)
        {
            maxi = temp;
        }
    }
}
void print(int a[],int n)
{
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int rain(int a[],int n)
{
    int rm[n];
    int lm[n];
    for(int i=0;i<n;i++)
    {
       lm[i] = rm[i] = a[i];
    }
    right(rm,n);
    left(lm,n);
    int sum =0;
    for(int i=0;i<n;i++)
    {
        lm[i] = min(lm[i],rm[i]);
        rm[i] = max((lm[i]-a[i]),0);
        sum += rm[i];
    }
    return sum;
}

int main()
{
    int a[] = {0,3,2,1,4,5,6,0,8};
    int n = sizeof(a)/sizeof(int);
    int ans = rain(a,n);
    cout<<"total water trapped is : "<<ans<<endl;
    //left(a,n);
    //right(a,n);
    //print(a,n);
    return 0;
}
