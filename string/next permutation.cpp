#include<bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int idx = -1;
        for(int i= N-1 ; i>0 ; i--)
        {
            if(arr[i] > arr[i-1])
            {
                idx = i;
                break;
            }
        }
        if(idx == -1)
        {
            sort(arr.begin(),arr.end());
        }
        else
        {
            int prev = idx;
            for(int i=idx+1 ; i<N; i++)
            {
                if(arr[idx-1] < arr[i] and arr[i] <= arr[prev])
                {
                    prev = i;
                }
            }
            swap(arr[prev],arr[idx-1]);
            reverse(arr.begin()+idx, arr.end());
        }
        return arr;
}

int main()
{
    vector<int>vec = {1,2,3,6,5,4};
    vec = nextPermutation(vec.size(), vec);
    for(auto elm : vec)
    {
        cout<<elm<<" ";
    }
    cout<<endl;
    return 0;
}
