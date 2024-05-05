#include<bits/stdc++.h>
using namespace std;
void smerge(int a[],int b[],int n,int m)
{
    int i = n-1;
    int j=0;
    while(i>0 && j<m)
    {
        if(a[i]>b[j])
        {
            swap(a[i],b[j]);
            j++;
            i--;
        }
        else{
            break;
        }
    }
    sort(a,a+n);
    sort(b,b+m);
}
int main()
{
    int a[] = {1,5,9,10,15,20};
    int n = sizeof(a)/sizeof(int);
    int b[] = {2,3,8,13};
    int m = sizeof(b)/sizeof(int);
    cout<<"first array is : "<<endl;
    for(auto elm : a)
    {
        cout<<elm<<" ";
    }
    cout<<endl<<"second array is "<<endl;
    for(auto elm : b)
    {
        cout<<elm<<" ";
    }
    smerge(a,b,n,m);
    cout<<endl<<"after merging first array is : "<<endl;
    for(auto elm : a)
    {
        cout<<elm<<" ";
    }
    cout<<endl<<"second array is "<<endl;
    for(auto elm : b)
    {
        cout<<elm<<" ";
    }
    return 0;
}
