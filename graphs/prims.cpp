#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;
int adj[][8]=
{
    {I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}
};
int near[8]= {I,I,I,I,I,I,I,I};
int t[2][6];
int main()
{
    int i,j,k,u,v,n=7,mini=I;
    for(i=1; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            if(adj[i][j]<mini)
            {
                mini=adj[i][j];
                u=i;
                v=j;
            }
        }
    }
    t[0][0]=u;
    t[1][0]=v;
    near[u]=near[v]=0;
    for(i=1; i<=n; i++)
    {
        if(near[i]!=0)
        {
            if(adj[i][u]<adj[i][v])
                near[i]=u;
            else
                near[i]=v;
        }
    }
    for(i=1; i<n-1; i++)
    {
        mini=I;
        for(j=1; j<=n; j++)
        {
            if(near[j]!=0 && adj[j][near[j]]<mini)
            {
                k=j;
                mini=adj[j][near[j]];
            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        for(j=1; j<=n; j++)
        {
            if(near[j]!=0 && adj[j][k]<adj[j][near[j]])
                near[j]=k;
        }
    }
    for(i=0; i<n-1; i++)
    {
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }
    int ans =0;
    for(i=0;i<n-1;i++)
    {
       ans = ans + adj[t[0][i]][t[1][i]];
    }
    cout<<endl<<endl<<"ans is : "<<ans<<endl;
}


