#include<bits/stdc++.h>
using namespace std;
void bubble(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}
int main()
{
    int arr[] = {4,3,2,1,5,7,6,9,8,10};
    bubble(arr,10);
    for(auto elm : arr)
        cout<<elm<<" ";
}