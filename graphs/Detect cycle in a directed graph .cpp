// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checked(vector<int> adj[], vector<int>&v,int i)
    {
        if(v[i] == 1) return true;
        if(v[i] == 0)
        {
            v[i] =1;
            for(auto e : adj[i])
            {
                if( checked(adj,v,e))
                return true;
            }
        }
        v[i] =2;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>v(V,0);
        for(int i=0;i<V;i++)
        {
            if(v[i] == 0)
            {
                if(checked(adj,v,i))
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends