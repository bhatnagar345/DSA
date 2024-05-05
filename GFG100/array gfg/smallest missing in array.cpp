#include<iostream>
using namespace std;
void smallest(int a[],int low , int high)
{
    if(low>high)
    {
        cout<<"the smallest missing number is : "<<low<<endl;
        return;
    }
    int mid ;
    mid = (low + high)/2;
    if(mid == a[mid])
    {
        smallest(a,mid+1,high);
    }
    else
    {
        smallest(a,low,mid-1);
    }
}
int main()
{
    int a[] = {0,1,2,3,5,6,7};
    smallest(a,0,6);
    return 0;
}
