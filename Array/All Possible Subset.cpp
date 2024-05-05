#include<bits/stdc++.h>
using namespace std;

void SubRecurFunc(vector<int>vec,vector<vector<int>> &ans,vector<int> &subset,int index)
{
    ans.push_back(subset);
    for(int i= index;i<vec.size();i++)
    {
        subset.push_back(vec[i]);
        SubRecurFunc(vec,ans,subset,i+1);
        for(int i=1;i<ans.size();i++)
        subset.pop_back();
    }
    return;
}

vector<vector<int>> subfunc(vector<int>vec)
{
    vector<vector<int>>ans;
    vector<int>subset;
    int index =0;
    SubRecurFunc(vec,ans,subset,index);
    return ans;
}
int main()
{
    vector<int> vec = {1,2,3};
    vector<vector<int>>ans = subfunc(vec);
    cout<<"[]"<<endl;
    for(int i=1;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<"["<<ans[i][j]<<"]";
        }
        cout<<endl;
    }
    return 0;
}
