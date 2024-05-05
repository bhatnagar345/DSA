/*Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.


Example 1:

Input:
N = 3
arr[] = {1, 0, 1}
M = 1
Output:
3
Explanation:
Maximum subarray is of size 3
which can be made subarray of all 1 after
flipping two zeros to 1.
Example 2:

Input:
N = 11
arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
M = 2
Output:
8
Explanation:
Maximum subarray is of size 8
which can be made subarray of all 1 after
flipping two zeros to 1.
*/



#include<iostream>
using namespace std;
int findZeroes(int arr[], int n, int m)
{
    // code here
    int j=-1;
    int count = 0;
    int ans =0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] ==0)
        {
            count++;
        }
        while(count>m)
        {
            j++;
            if(arr[j] ==0)
            {
                count--;
            }
        }
        int len = i-j;
        if(len>ans)
        {
            ans = len;
        }
    }
    return ans;
}
int main()
{
    int a[] = {1,0,0,1,1,0,1,0,1,1,1};
    int n = sizeof(a)/sizeof(int);
    int m = 2;
    int ans = findZeroes(a,n,m);
    cout<<"the total lenght of subarray with m number of flips of 0 in array : "<<ans<<endl<<1/2<<endl;
    return 0;
}
