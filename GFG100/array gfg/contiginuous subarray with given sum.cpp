/*
Given an unsorted array of nonnegative integers, find a continuous subarray which adds to a given number.
Examples :

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4
Sum of elements between indices
2 and 4 is 20 + 3 + 10 = 33

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Ouptut: Sum found between indexes 1 and 4
Sum of elements between indices
1 and 4 is 4 + 0 + 0 + 3 = 7

Input: arr[] = {1, 4}, sum = 0
Output: No subarray found
There is no subarray with 0 sum
*/

#include<iostream>
using namespace std;
void subarray(int a[],int n,int sum)
{
    int lef=0;
    int rig=0;
    int curr=0;
    int ans =0;
    while(rig<n)
    {
        if(curr == sum)
        {
            cout<<"sum found between "<<lef+1<<" and "<<rig<<endl;
            return;
        }
        if(curr>sum) 
        { 
            curr = curr - a[lef];
            lef++;
        }
        else{
            curr = curr + a[rig];
            rig++;
        }
    }
    cout<<"we did not get subarray of given sum "<<endl;
}
int main()
{
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int sum = 23;
    int n = sizeof(arr)/sizeof(int);
    subarray(arr,n,sum);
    return 0;
}

