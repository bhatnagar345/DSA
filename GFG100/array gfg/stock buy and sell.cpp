/*The cost of a stock on each day is given in an array, find the max profit
that you can make by buying and selling in those days.
For example, if the given array is {100, 180, 260, 310, 40, 535, 695},
the maximum profit can earned by buying on day 0,
selling on day 3. Again buy on day 4 and sell on day 6.
If the given array of prices is sorted in decreasing order,
then profit cannot be earned at all.
*/

#include<bits/stdc++.h>
using namespace std;
void  stock(int a[],int n)
{
    int sell,buy;
    int i=0;
    while(i<n-1)
    {
        while(i < n && ( a[i] >= a[i+1] ))
        {
            i++;
        }
        if(i == n-1)
        {
            break;
        }
        cout<<" we buy the product on day : "<<i++;
        while(i<n && (a[i] >=a[i-1]))
        {
            i++;
        }
        cout<<" and sell it on day : "<<i-1<<endl;
    }
}
int main()
{
    int a[]= {10,18,20,31,4,53,69};
    int n = sizeof(a)/sizeof(int);
    stock(a,n);
    return 0;
}
