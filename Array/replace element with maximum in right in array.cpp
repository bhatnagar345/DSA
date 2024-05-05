/*Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array.
Since there is no element next to the last element, replace it with -1. For example,
if the array is {16, 17, 4, 3, 5, 2}, then it should be modified to {17, 5, 5, 5, 2, -1}.
    */
#include<iostream>
using namespace std;
void replacemaxi(int a[],int n)
{
    int maxi=-1;
    int temp;
    for(int i=n-1;i>=0;i--)
    {
        temp = a[i];
        a[i] = maxi;
        if(maxi < temp)
            maxi = temp;
    }
}
int main()
{
    int a[] = {16,17,4,3,5,2};
    int n = sizeof(a)/sizeof(n);
    replacemaxi(a,n);
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
