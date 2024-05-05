/*Given an array of positive integers. All numbers occur an even number of
times except one number which occurs an odd number of times. Find the number in O(n) time & constant space.
Examples :

Input : arr = {1, 2, 3, 2, 3, 1, 3}
Output : 3

Input : arr = {5, 7, 2, 7, 5, 2, 5}
Output : 5*/
#include<iostream>
using namespace std;
int odd(int a[],int n)
{
    int num =0;
    for(int i=0;i<n;i++)
    {
        num = num ^ a[i];
    }
    return num;
}
int main()
{
      int a[]={2,3,4,5,14,3,3,2,4,3,5,2,4,4,2};
      cout<<odd(a,15)<<endl;

    return 0;
}
