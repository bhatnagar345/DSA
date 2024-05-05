/*
Input: array = {12, 3, 4, 1, 6, 9}, sum = 24;
Output: 12, 3, 9
Explanation: There is a triplet (12, 3 and 9) present
in the array whose sum is 24.
Input: array = {1, 2, 3, 4, 5}, sum = 9
Output: 5, 3, 1
Explanation: There is a triplet (5, 3 and 1) present
in the array whose sum is 9.
*/

#include<bits/stdc++.h>
using namespace std;

void triplet(int A[],int n,int X)
{
     int i=0;
    sort(A,A+n);
    for(i;i<n-2;i++)
    {
        int left = i+1;
        int right = n-1;
        while(left < right)
        {
            if(A[i] + A[left] + A[right] == X)
            {
            cout<<A[i]<<" "<<A[left]<<" "<<A[right]<<endl<<endl;
            return;
            }
            else if(A[i] + A[left] + A[right] < X)
            left++;
            else
            right--;
        }
    }
    cout<<"there is not triplet"<<endl<<endl;
}

int main()
{
    int arr[] = {12, 3, 4, 1, 6, 9};
    int  sum = 24;
    int n = sizeof(arr)/sizeof(int);
    triplet(arr,n,sum);
    return 0;
}
