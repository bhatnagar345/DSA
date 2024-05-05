//rotate matrix to 90 degree



#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &v)
{
    int i=0;
    int j=v.size()-1;
    while(i<j)
    {
        swap(v.at(i),v.at(j));
        i++;
        j--;
    }
}

void rotatemat(vector<vector<int>> & v)
{
    int n = v.size();
    int m = v[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(v[i][j] , v[j][i]);
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        reverse(v[i]);
    }
}
int main()
{
    vector<vector<int>>vec = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotatemat(vec);
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
