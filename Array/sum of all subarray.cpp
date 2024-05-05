#include<iostream>
using namespace std;
void sumsub(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int sum = 0;
    for(int j=i;j<n;j++)
    {
        sum +=a[j];
        cout<<sum<<endl;
    }
    }
}
int main()
{
    int a[] = {1,2,3,0,4,5};
    sumsub(a,6);
    return 0;
}
