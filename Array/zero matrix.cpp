//if there is a zero in matrix fill that row and colomun with zeros
#include<bits/stdc++.h>
using namespace std;
void zero(vector<vector<int>> & v)
{
    bool row[v.size()] ={false};
    bool col[v[0].size()] = {false};
    for(int i = 0; i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            if(v[i][j]==0)
            {
            row[i]=true;
            col[j]=true;
            }
        }
    }
    for(int i = 0; i<v.size();i++)
    {
        if(row[i])
        {
            for(int j=0;j<v[0].size();j++)
            {
                v[i][j]=0;
            }
        }
    }
    for(int j=0;j<v[0].size();j++)
    {
        if(col[j])
        {
          for(int i = 0; i<v.size();i++)
          {
              v[i][j]=0;
          }
        }
    }
}


int main()
{
    vector<vector<int>>vec = {{1,2,3,4},{0,6,7,8},{9,10,11,12},{13,14,15,16}};
    zero(vec);
    for(auto elm: vec)
    {
        for(auto e : elm)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    return 0;
}
