
/*Given an array arr[] of n integers, construct a Product Array prod[] (of same size)
such that prod[i] is equal to the product of all the elements of arr[] except arr[i].
 Solve it without division operator in O(n) time.
Example :

Input: arr[]  = {10, 3, 5, 6, 2}
Output: prod[]  = {180, 600, 360, 300, 900}
3 * 5 * 6 * 2 product of other array
elements except 10 is 180
10 * 5 * 6 * 2 product of other array
elements except 3 is 600
10 * 3 * 6 * 2 product of other array
elements except 5 is 360
10 * 3 * 5 * 2 product of other array
elements except 6 is 300
10 * 3 * 6 * 5 product of other array
elements except 2 is 900
*/
#include<iostream>
using namespace std;
void product(int a[], int n)
{
    int pro[n];
    int m=0;
    int prod=1;
    for(int i=0;i<n;i++)
    {
        prod = prod *a[i];
    }
    for(int i=0;i<n;i++)
    {
        pro[i]= prod/a[m];
        m++;
    }
    for(auto elm : pro)
    {
        cout<<elm<<" ";
    }
}
int main()
{
    int a[]= {3,5,10,6,2};
    int n = 5;
    product(a,n);
    return 0;
}
