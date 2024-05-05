//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        
        vector<int>dis(V,INT_MAX);
        set<pair<int,int>>s;
        dis[S] = 0;
        s.insert({0,S});
        while(!s.empty())
        {
           auto node = *(s.begin());
           int distance = node.first;
           int source = node.second;
           s.erase(node);
           for(auto nnode : adj[source])
           {
               if((distance + nnode[1]) < dis[nnode[0]] )
               {
                   auto record = s.find({dis[nnode[0]], nnode[0]});
                   if(record != s.end())
                   {
                       s.erase(record);
                   }
                   dis[nnode[0]] = distance + nnode[1];
                   s.insert({dis[nnode[0]],nnode[0]});
               }
           }
        }
        return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends