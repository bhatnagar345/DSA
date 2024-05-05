#include<bits/stdc++.h>
using namespace std;
bool ans = true;
void DFStraversal(int g[][7], int start , int N)
{
       static int visited[7] = {0};
    int j;
    if(visited[start] ==0)
    {
        cout<<start<<" ";
        visited[start]++;
        for(j =1;j<=N;j++){
            if(g[start][j] == 1 && visited[j] == 0){
                DFStraversal(g,j,N);
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
    string a;
    cout<<"write the string : ";
    cin>>a;
    DFStraversal(G,4,7);
    return 0;
}

