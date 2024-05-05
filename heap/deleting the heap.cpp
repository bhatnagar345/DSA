
#include<iostream>
using namespace std;
void maxHeap(int arr[],int n)
{
    int i = n;
    int temp = arr[n];
    while(i>0 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i]  = temp;
}

int delet(int arr[], int n)
{
     int i;
    int temp = arr[n];
    arr[n] = arr[0];
    arr[0] = temp;
    i =0;
    int j = i+1;
    while(j<n-1){
        if(arr[j] < arr[j+1]){
            j = j+1;
        }
        if(arr[i] < arr[j])
        {
            swap(arr[i],arr[j]);
            i = j;
            j = j*2;
        }
        else{
            break;
        }
    }
    return arr[n];
}


int main()
{
    int arr[]={10,5,6,15,12,20,35,30,40,50 };
    int i = 0;
    int n = sizeof(arr)/sizeof(int);
    for( i=1;i<n;i++)
    {
        maxHeap(arr,i);
    }
    cout<<"the max heap is " <<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"->";
    }
    cout<<"NULL"<<endl;
    for(i=n-1;i>=0;i--)
    {
        cout<<"the deleted value is "<<delet(arr,i)<<endl;
    }
    if(arr[0]>arr[1]){
        swap(arr[1],arr[0]);
    }
    cout<<"the heap sort is " <<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"->";
    }
    return 0;
}
