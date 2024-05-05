/*
Pythagorean Triplet
Given an array arr of N integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2, otherwise false.

Example 1:

Input:
N = 5
Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.
Example 2:

Input:
N = 3
Arr[] = {3, 8, 5}
Output: No
Explanation: No such triplet possible.
*/


#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[a[i]] += 1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int p = sqrt(a[i]*a[i] + a[j]*a[j]);
            float q = sqrt(a[i]*a[i] + a[j]*a[j]);
            if(p == q && m[p])
            {
                cout<<"the triplet is : "<<a[i]<<" "<<a[j]<<" "<<p<<endl;
                return;
            }
        }
    }
    cout<<"there is no triplet "<<endl;
}

int main()
{
    int Arr[] = {3, 2, 4, 6, 5};
    int n = sizeof(Arr)/sizeof(int);
    solve(Arr,n);
    return 0;
}
