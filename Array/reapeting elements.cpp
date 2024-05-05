/*
You are given an array of n+2 elements. All elements of the array are in range 1 to n.
And all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Example:

Input:
arr = [4, 2, 4, 5, 2, 3, 1]
n = 5
Output:
4 2
Explanation:
The above array has n + 2 = 7 elements with all elements occurring once except 2 and 4 which occur twice. So the output should be 4 2.
*/
#include<bits/stdc++.h>
using namespace std;
void reapeting(int a[],int n)
{
    cout<<"repeating elements are : ";
    for(int i=0;i<n;i++)
    {
        if(a[abs(a[i])]>0)
        {
            a[abs(a[i])]= -a[abs(a[i])];
        }
        else
        {
         cout<<abs(a[i])<<" ";
        }
    }
}

int main()
{
    int a[]= {4,2,4,5,1,1,3};
    reapeting(a,7);
    return 0;
}
