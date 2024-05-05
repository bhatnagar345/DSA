/*Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements.
Example :

Input :  arr[] = [1, 2, 3, 4, 5, 6, 7]
         d = 2
Output : arr[] = [3, 4, 5, 6, 7, 1, 2]
*/

#include<iostream>
using namespace std;
void revers(int a[],int start, int end)
{
    while(start < end)
    {
        swap(a[start],a[end]);
        start++;
        end--;
    }
}

void rotat(int a[],int n , int d)
{
    d = d%n;
    if(d == 0)
    {
        return;
    }
    revers(a,0,n-1);
    revers(a,0,n-d-1);
    revers(a,n-d,n-1);
}
int main()
{
    int a[] = {1,2,3,4,5,6,7};
    int n = sizeof(a)/sizeof(int);
    int diff = 3;
    rotat(a,n,diff);
    cout<<"[ ";
    for(auto el : a)
    {
        cout<<el<<" ";
    }
    cout<<"] "<<endl;
    return 0;
}
