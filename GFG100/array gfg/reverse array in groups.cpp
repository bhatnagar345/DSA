/*
Reverse array in groups
Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.



Example 1:

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.


Example 2:

Input:
N = 4, K = 3
arr[] = {5,6,8,9}
Output: 8 6 5 9
*/

#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int n,int k)
{
    for(int i=0;i<n;i+=k)
    {
        int left = i;
        int right = min(i+k-1,n-1);
        while(left<right)
        {
            swap(a[left++],a[right--]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int k=2;
    solve(arr,n,k);
    return 0;
}
