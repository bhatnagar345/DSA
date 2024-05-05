#include<iostream>
using namespace std;
int main()
{
    int a[]= {0,1,0,1,0,1,0,1,0,1};
    int n = sizeof(a)/sizeof(int);
    int i=0;
    int j = n-1;
    while(i<j)
    {
        while(!a[i] && i<j)
        {
            i++;
        }
        while(a[j] && i<j)
        {
            j--;
        }
        swap(a[i],a[j]);
    }
    cout<<"[ ";
    for(auto el : a)
    {
        cout<<el<<" ";
    }
    cout<<"] "<<endl;
    return 0;
}
