// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
        bool checkForCycleDFS(int node,int parent,vector<int> & visited ,vector<int> adj[])
   {
       visited[node]=1;
       for(auto u:adj[node])
       {
           if(visited[u]==0)
           {
               if(checkForCycleDFS(u,node,visited,adj)) 
                   return true;  
           }else if(u!=parent) 
                   return true;
       }
       return false;
   }
   bool checkForCycleBFS(int s,vector<int> &visited,vector<int> adj[])
   {
       queue<pair<int,int>> q;
       q.push({s,-1});
       visited[s]=1;
       while(!q.empty())
       {
           int node=q.front().first;
           int parent=q.front().second;
           q.pop();
           for(auto u:adj[node])
           {
               if(visited[u]==0)
               {
                   q.push({u,node});
                   visited[u]=1;
               }else if(parent!=u)
               {
                   return true;
               }
           }
       }
       return false;
   }
   bool isCycle(int V, vector<int> adj[]) {
       // Code here
       vector<int> visited(V,0);
       for(int i=0;i<V;i++)
       {
           if(visited[i]==0)
           {
                if(checkForCycleDFS(i,-1,visited,adj))
                    return true;
            //   if(checkForCycleBFS(i,visited,adj))
            //       return true;
           }
       }
       return false;
   }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends