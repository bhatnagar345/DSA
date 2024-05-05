// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to
//reach the target position.

// Note:
// The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

// Example 1:

// Input:
// N=6
// knightPos[ ] = {4, 5}
// targetPos[ ] = {1, 1}
// Output:
// 3
// Explanation:

// Knight takes 3 step to reach from 
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
     public:
    bool isValid(int ada, int bdb, int N){
      if(ada < 0 || ada >= N || bdb < 0 || bdb >= N){
          return false;
      }
      return true;
  }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   int x = TargetPos[0] - 1;
	   int y = TargetPos[1] - 1;
	   int i = KnightPos[0] - 1;
	   int j = KnightPos[1] - 1;
	   vector<vector<bool>> visited;
	   for(int i = 0; i < N; i++){
	       vector<bool> v (N, false);
	       visited.push_back(v);
	   }
	   visited[i][j] = true;
	   int dx[8] = {2,2,-2,-2,1,-1 , 1, -1};
        int dy[8] = {1,-1,1,-1,2,2,-2,-2};
	   queue<pair<int, int>> q;
	   q.push({i, j});
	   int cnt = 0;
	   while(q.empty() == false){
	       int sz = q.size();
	       for(int i = 0; i < sz; i++){
	           int a = q.front().first;
	           int b = q.front().second;
	           q.pop();
	           if(a == x && b == y){
	               return cnt;
	           }
	           for(int k = 0; k < 8; k++){
	               int ada = a + dx[k];
	               int bdb = b + dy[k];
	               if(isValid(ada, bdb, N) && visited[ada][bdb] == false){
	                   visited[ada][bdb] = true;
	                   q.push({ada, bdb});
	               }
	           }
	       }
	       cnt++;
	   }
	   return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends