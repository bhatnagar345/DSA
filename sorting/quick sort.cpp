#include<iostream>
using namespace std;
void swapi(int &a,int &b)
{
    int temp;
    temp =a;
    a=b;
    b=temp;
}
int partitio(int a[], int s,int l)
{
    int pivot = a[l];
    int i = s-1;
    for(int j = s; j<l;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swapi(a[i],a[j]);
        }
    }
    swapi(a[i+1],a[l]);
    return i+1;
}
void quicksort(int a[],int start, int en)
{

    int j;
    if(start<en)
    {
        j = partitio(a,start,en);
        quicksort(a,start,j-1);
        quicksort(a,j+1,en);

    }
}
int main()
{
    int a[]= {9,8,7,6,5,4,3,2,1};
    int s =0;
    int l = 8;
    quicksort(a,s,l);
    for(auto elm : a)
    {
        cout<<elm<<" ";
    }
    return 0;
}
