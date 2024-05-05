#include<bits/stdc++.h>
using namespace std;

vector<int> duplicates(int arr[], int n)
{
    // code here
    vector<int>vec;
    int maxi =0;
    for(int i=0; i<n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int has[maxi +1] = {0};
    for(int i=0; i<n; i++)
    {
        has[arr[i]]++;
        if(has[arr[i]] == 2)
        {
            vec.push_back(arr[i]);
        }

    }

    if(vec.empty())
    {
        vec.push_back(-1);
    }

    for(auto elm : vec)
    {
        cout<<elm<<endl;
    }
}
int main()
{
    int a[] = {1,2,3,2,3};
    int n = sizeof(a)/sizeof(int);
    duplicates(a,n);
    return 0;
}

