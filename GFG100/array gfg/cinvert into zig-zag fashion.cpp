/*
Given an array Arr (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. 
The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output 
i.e you have to iterate on the original array only.

Example 1:

Input:
N = 7
Arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 3 7 4 8 2 6 1
Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
Example 2:

Input:
N = 4
Arr[] = {1, 4, 3, 2}
Output: 1 4 2 3
Explanation: 1 < 4 > 2 < 3
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int a[] , int n)
{
    bool flag = true;
    for(int i=0;i<n-1;i++)
    {
        if(flag)
        {
            if(a[i]>a[i+1])
            swap(a[i],a[i+1]);
        }
        else{
            
            if(a[i]<a[i+1])
            swap(a[i],a[i+1]);
        }
        flag = !flag;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}
int main()
{
    int Arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(Arr)/sizeof(int);
    solve(Arr,n);
    return 0;
}