#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Merge(int A[],int low,int mid,int high)
{
     int ans[high - low + 1];
    int left = low, i = 0;
    int right = mid + 1;

    while(left <= mid && right <= high){

        if(arr[left] <= arr[right]){
            // ans.push_back(arr[left]);
            ans[i++] = arr[left];
            left++;
        }
        else{
            // ans.push_back(arr[right]);
            ans[i++] = arr[right];
            right++;
        }
    }

    while(left <= mid){
        // ans.push_back(arr[left]);
            ans[i++] = arr[left];
            left++;
    }
    while(right <= high){
        //   ans.push_back(arr[right]);
            ans[i++] = arr[right];
            right++;
    }

    for(int i = low; i<= high; i++){
        arr[i] = ans[i - low];
    }
}
void mergeSort(int A[],int const begin , int const end)
{
    if (begin >= end)
        return; // Returns recursivly

    auto mid = begin + (end - begin) / 2;
    mergeSort(A, begin, mid);
    mergeSort(A, mid + 1, end);
    Merge(A, begin, mid, end);

}
int main()
{
    int A[]= {11,13,7,12,16,9,24,5,10,3},n=10,i;

    mergeSort(A,0,n-1);

    for(i=0; i<10; i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}
