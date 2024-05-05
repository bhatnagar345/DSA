/*Write a program to print all the LEADERS in the array.
An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader.
For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
Let the input array be arr[] and size of the array be size.
*/
#include<iostream>
using namespace std;
int main()
{
    int a[]= {16,17,4,3,4,5,2};
    int n = sizeof(a)/sizeof(int);
    int max =0;
    cout<<a[n-1]<<endl;
    max = a[n-1];
    for(int i = n-2;i>=0;i--)
    {
        if(max < a[i])
        {
            max = a[i];
            cout<<max<<endl;
        }
    }
    return 0;
}
