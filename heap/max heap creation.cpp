#include<iostream>
using namespace std;
void maxHeap(int a[],int n)
{
    int i = n;
    int temp = a[n];
    while(i>1 && temp > a[i/2])
    {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i]  = temp;
}


int main()
{
    int a[]={0,10,5,6,15,12,20,35,30,40,50};
    int i = 0;
    for( i=2;i<11;i++)
    {
        maxHeap(a,i);
    }
    cout<<"the max heap is " <<endl;
    for(i=0;i<11;i++)
    {
        cout<<a[i]<<"->";
    }
    cout<<"NULL"<<endl;
}
