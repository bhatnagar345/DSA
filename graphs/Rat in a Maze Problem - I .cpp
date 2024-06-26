// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>v;
    void dfs(int i,int j, string s,vector<vector<int>> &m,int n, vector<vector<int>>&visi)
    {
        if(i<0 or j<0 or i>=n or j>= n)return;
        if(m[i][j] == 0 or visi[i][j] == 1) return;
        if(i == n-1 and j == n-1)
        {
            v.push_back(s);
            return;
        }
        visi[i][j] =1;
        dfs(i-1,j,s+ "U",m,n,visi);
        dfs(i+1,j,s+"D",m,n,visi);
        dfs(i,j-1,s+"L",m,n,visi);
        dfs(i,j+1,s+"R",m,n,visi);
        visi[i][j] =0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        v.clear();
        vector<vector<int>>visi(n,vector<int>(n,0));
        if(m[0][0] ==0)return v;
        if(m[n-1][n-1] == 0) return v;
        string s = "";
        dfs(0,0,s,m,n,visi);
        sort(v.begin(),v.end());
        return v;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends