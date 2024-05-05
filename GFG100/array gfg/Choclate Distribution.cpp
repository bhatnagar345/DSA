/*
Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. 
Each packet can have a variable number of chocolates
.There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between
maximum chocolates and minimum chocolates
is 9 - 3 = 6 by choosing following M packets :
{3, 4, 9, 7, 9}.
*/



#include<bits/stdc++.h>
using namespace std;

void choclate(int a[],int n,int m)
{
    sort(a,a+n);
    int mini = INT_MAX;
    for(int i=0;i+m-1<n;i++)
    {
        int d = a[i+m-1]-a[i];
        if(d<mini)
            mini = d;
    }
    cout<<"ans : "<<mini<<endl;
}
int main()
{
    int a[] ={3, 4, 1, 9, 56, 7, 9, 12};
    int n = sizeof(a)/sizeof(int);
    int m = 5;
    choclate(a,n,m);
    return 0;
}
