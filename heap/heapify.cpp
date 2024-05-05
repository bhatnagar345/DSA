#include<bits/stdc++.h>
using namespace std;
void Heapify(int a[], int n, int index)
{
    int lar = index;
    int left = index*2;
    int right = index*2 +1;
    if(left<n && a[left]> a[index])
    {
        lar = left;
    }
    if(right < n && a[right] > a[lar])
    {
        lar = right;
    }
    if(lar != index)
    {
        swap(a[index], a[lar]);
        Heapify(a,n,lar);
    }
}
int delet(int a[],int n)
{
    int temp = a[1];
    a[1] = a[n];
    a[n] = temp;
    int i =1;
    int j=i+1;
    while(j<n-1)
    {
        if(a[j] < a[j+1])
        {
            j = j+1;
        }
        if(a[i] < a[j])
        {
            swap(a[i],a[j]);
            i = j;
            j = j*2;
        }
        else{
            break;
        }
    }
    return a[n];
}



int main()
{
    int arr[]={0,10,5,6,15,12,20,35,30,40,50 };
    int i = 0;
    int n = sizeof(arr)/sizeof(int);
    for( i=n/2;i>0;i--)
    {
        Heapify(arr,n,i);
    }
    cout<<"the max heap is " <<endl;
    for(i=1;i<n;i++)
    {
        cout<<arr[i]<<"->";
    }
    cout<<"NULL"<<endl;
    for(i=n-1;i>=1;i--)
    {
        cout<<"the deleted value is "<<delet(arr,i)<<endl;
    }
    return 0;
}

