// Overlapping Intervals 
// Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

// Example 1:

// Input:
// Intervals = {{1,3},{2,4},{6,8},{9,10}}
// Output: {{1, 4}, {6, 8}, {9, 10}}
// Explanation: Given intervals: [1,3],[2,4]
// [6,8],[9,10], we have only two overlapping
// intervals here,[1,3] and [2,4]. Therefore
// we will merge these two and return [1,4],
// [6,8], [9,10].

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> overlappedInterval(vector<vector<int>>& a) {
         // Code here
         sort(a.begin(),a.end());
        stack<pair<int,int>>s;
        s.push({a[0][0],a[0][1]});
        for(int i=1;i<a.size();i++)
        {
            if(s.top().second >= a[i][0])
            {
                a[i][0] = s.top().first;
                if(s.top().second > a[i][1])
                a[i][1] = s.top().second;
                s.pop();
                s.push({a[i][0],a[i][1]});
            }
            else
            {
                s.push({a[i][0],a[i][1]});
            }
        }
        vector<vector<int>>vec;
        
        while(!s.empty())
        {
            vector<int>v;
            v.push_back(s.top().first);
             v.push_back(s.top().second);
             vec.push_back(v);
             s.pop();
        }
        sort(vec.begin(),vec.end());
        return vec;
    }
int main()
{
    vector<vector<int>>vec = {{1,3},{2,4},{6,8},{9,10}};
    vec = overlappedInterval(vec);
    for(auto l : vec)
    {
        // cout<<"{ ";
        for(auto e:l)
            cout<<e<<" ";
        // cout<<"}";
        cout<<endl;
    }
    return 0;
}
