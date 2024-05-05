#include<bits/stdc++.h>
using namespace std;

void BFS(int g[][7], int start , int N)
{
    int visited[N] = {0};
    int i = start;
    int j;
    cout<<i<<" ";
    queue<int>q;
    q.push(i);
    visited[i] =1;
    while(! q.empty())
    {
        i = q.front();
        q.pop();
        for(j = 1; j<= N;j++){
            if(g[i][j]== 1 && visited[j] == 0){
                visited[j]++;
                cout<<j<<" ";
                q.push(j);
            }
        }
    }
}
int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};

    BFS(G,1,7);
    return 0;
}
