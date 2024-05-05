/*
Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes. 
For example, in an array A:

Example :

Input: A[] = {-7, 1, 5, 2, -4, 3, 0}
Output: 3
3 is an equilibrium index, because:
A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

Input: A[] = {1, 2, 3}
Output: -1
*/

#include<bits/stdc++.h>
using namespace std;

int equilibriumPoint(int a[], int n) {

        // Your code here
        int sum =0;
        int esum =0;
        for(int i=0;i<n;i++)
        {
            esum += a[i];
        }
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(i !=0)
            sum += a[i-1];
            esum -= a[i];
            if(sum == esum)
            {
                ans = i+1;
                cout<<"index is : "<<ans<<endl;
                return ans;
            }

        }
        cout<<"there is no index "<<endl;
        return -1;
}
int main()
{
    int a[] = {1,3,5,2,2};
    int n = sizeof(a)/sizeof(int);
    equilibriumPoint(a,n);
    return 0;
}
