#include<bits/stdc++.h>
using namespace std;
long long merging(long long  a[],long long  temp[],long long left , long long mid ,long long right)
{
    long long  int ans =0;
    long long i =left,j=mid;
    long long k=left;
    while(i<mid && j<=right)
    {
        if(a[i]<=a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            ans += mid -i;
        }
    }
    for(i;i<mid;i++)
    {
     temp[k++] = a[i];
    }
    for(j;j<=right;j++)
    {
        temp[k++] = a[j];
    }
    for(long long  m = left ; m<= right;m++)
     {
      a[m] = temp[m];
     }
      return ans;
}

long long mergesort(long long a[],long long temp[],long long left,long long right)
{
    long long ans =0;
    if(left <right)
    {
        long long mid = (left + right)/2;
        ans += mergesort(a,temp,left,mid);
        ans += mergesort(a,temp,mid+1,right);
        ans += merging(a,temp,left,mid+1,right);
    }
    return ans;
}


//Brute Force Approach is
void bruteforce(long long a[],long long n)
{
    long long int ans =0;
    for(long long i=0;i<n;i++)
    {
        for(long long j=i;j<n;j++)
        {
            if(a[i]>a[j])
                ans++;
        }
    }
    cout<<"BruteForce Solution is : "<<ans<<endl<<endl;
}
int main()
{
    long long a[] = {2,4,1,3,5};
    long long n = sizeof(a)/sizeof(a[0]);

    bruteforce(a,n);

    cout<<"Optimal Solution is :";
    long long temp[n] ;
    long long  ans = mergesort(a,temp,0,n-1);
    cout<<ans<<endl<<endl;
    return 0;
}
