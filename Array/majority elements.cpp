/*Write a function which takes an array and prints the majority element (if it exists),
 otherwise prints “No Majority Element”. A majority element in an array A[] of size n
 is an element that appears more than n/2 times (and hence there is at most one such element). */
#include<iostream>
#include<array>
using namespace std;
void majority(int a[],int n)
{
    int half = n/2;
    int maxi = 0;
    for(int i =0;i<n;i++)
    {
        if(maxi<a[i])
        {
            maxi = a[i];
        }
    }
    int has[maxi]={0};
    for(int i=0;i<n;i++)
    {
        has[a[i]]++;
    }
    for(int i=0 ;i<maxi;i++)
    {
        if(has[i]>=half)
        {
            cout<<"majority element of array which presence is equal to the half size of array  : "<<i<<endl;
            return ;
        }
    }
    cout<<"there is not majority element"<<endl;
}
int main()
{
    int a[] = {1,2,3,3,3,2,3,4,5};
    int n = sizeof(a)/sizeof(int);
    majority(a,n);
    return 0;
}
