/*Given an array arr[], find the maximum j – i such that arr[j] > arr[i].

Examples :

  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
  Output: 6  (j = 7, i = 1)

  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
  Output: 8 ( j = 8, i = 0)

  Input:  {1, 2, 3, 4, 5, 6}
  Output: 5  (j = 5, i = 0)

  Input:  {6, 5, 4, 3, 2, 1}
  Output: -1
*/
#include<iostream>
using namespace std;
void maxij(int a[],int n)
{
    int maxi =-1;
    int c,b;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(a[j]>a[i] && maxi < (j-i) )
            {
                maxi = j-i;
                c=j;
                b=i;
            }
        }
    }
    cout<<"the maximum j-i : "<<maxi<<" and j= "<<c<<" i = "<<b<<endl;
}

int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(int);
    maxij(a,n);
    return 0;
}
