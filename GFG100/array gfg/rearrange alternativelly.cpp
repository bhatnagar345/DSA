#include<bits/stdc++.h>
using namespace std;
void rearrange(int a[],int n)
{
    int maxi = n-1;
    int mini =0;
    int maxelm = a[n-1] +1;
    for(int i=0;i<n;i++)
    {
        if(i%2 ==0)
        {
            a[i] += (a[maxi]%maxelm)*maxelm;
            maxi--;
        }
        else{
            a[i] += (a[mini]%maxelm)*maxelm;
            mini++;
        }
    }
    for(int i=0;i<n;i++)
    {
        a[i] = a[i]/maxelm;
    }
}
//Brute Force Approach
void bruteforce(int a[] , int n)
{
    int temp[n];
    int k=0;
    int i=0,j=n-1;
    while(i<=j)
    {
        temp[k++] = a[j--];
        temp[k++] = a[i++];
    }
    for(auto elm : temp)
    {
        cout<<elm<<" ";
    }
    cout<<endl<<endl;
}
int main()
{
    int a[] = {10,20,30,40,50,60,70,80,90,100,110};
    int n = sizeof(a)/sizeof(a[0]);
    bruteforce(a,n);
    rearrange(a,n);
    for(auto el : a)
    {
        cout<<el<<" ";
    }
    cout<<endl;
    cout<<endl;
    return 0;
}
