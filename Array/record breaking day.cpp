//find the larger elements that is larger than the each of previous larger elements and following element
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"write down the number of elements  in array"<<endl;
    cin>>n;
    int a[n];
    cout<<"write down the array "<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    int maxi[n];
    maxi[0]=0;
    int sum = 0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(i==n-1 && a[i]>maxi[j])
        {
            j++;
            sum++;
            maxi[j] = a[i];
        }
        else if(a[i]>maxi[j] && a[i]> a[i+1])
        {
            j++;
            sum++;
            maxi[j] = a[i];
        }
    }
    cout<<"recording breaking days are : "<<sum<<endl;
    for(int i=1;i<=j;i++)
    {
    cout<<"the days "<<maxi[i] <<endl;
    }
    return 0;
}
