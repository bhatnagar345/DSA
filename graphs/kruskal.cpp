#include<bits/stdc++.h>
using namespace std;
#define I INT_MAX;
const int vertex = 7;
const int edges = 10;
int weight[edges][3] =  {{1,2,28},{1,6,10},{2,3,16},{2,7,14},{3,4,12},
{4,5,22},{4,7,18},{5,6,25},{5,7,24}};


int sets[vertex+1];
int included[edges] = {0};
int t[2][vertex-1];

void union_of_set(int u , int v)
{
    if(sets[u] < sets[v])
    {
        sets[u] = sets[u] + sets[v];
        sets[v] = u;
    }
    else{
        sets[v] = sets[u] + sets[v];
        sets[u] = v;
    }
}
int find_of_setelement(int u)
{
    int x = u;
    while(sets[x] >0){
        x = sets[x];
    }
    return x;
}

int main()
{
    int i=0,u,v,n = vertex-1,j,k;
    for(int h =0; h<vertex+1 ; h++){
        sets[h] = -1;
        //cout<<sets[h]<<endl;
    }
    while(i < n)
    {
        int mini = I;
        for( j=0 ; j< edges ;j++){
            if(included[j] == 0 && weight[j][2] < mini){
                mini = weight[j][2];
                u = weight[j][0];
                v = weight[j][1];
                k=j;
            }
        }
        if(find_of_setelement(u) != find_of_setelement(v)){
            t[0][i] = u;
            t[1][i] = v;
            union_of_set(find_of_setelement(u) , find_of_setelement(v));
            included[k] = 1;
            i++;
        }
        else{
        included[k] = 1;
        }
    }
    for(i=0; i<n; i++)
    {
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }
    int ans = 0;
    for(i=0;i<edges; i++)
    {
        for(j=0; j<n ; j++){
            if(weight[i][0] == t[0][j] && weight[i][1] == t[1][j]){
                ans = ans + weight[i][2];
            }
        }
    }
    cout<<endl<<endl<<"the total weight of spanning tree is : "<<ans<<endl<<endl;
    return 0;
}

