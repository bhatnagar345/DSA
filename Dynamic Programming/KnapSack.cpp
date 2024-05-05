#include<bits/stdc++.h>
using namespace std;
// std::ios::sync_with_stdio(false);
// int knapSack(int W, int wt[], int val[], int n)
// {
//     int i, w;
//       vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
//     // Build table K[][] in bottom up manner
//     for(i = 0; i <= n; i++)
//     {
//         for(w = 0; w <= W; w++)
//         {
//             if (i == 0 || w == 0)
//                 K[i][w] = 0;
//             else if (wt[i - 1] <= w)
//                 K[i][w] = max(val[i - 1] +
//                                 K[i - 1][w - wt[i - 1]],
//                                 K[i - 1][w]);
//             else
//                 K[i][w] = K[i - 1][w];
//         }
//     }
//     return K[n][W];
// }


int dp[1005][1005];
    int solve(int W,int wt[],int val[],int n){
        if(n == 0 or W == 0){
            return 0;
        }
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        if(wt[n-1]>W){
            return dp[n][W] = solve(W,wt,val,n-1);
        }
        return dp[n][W] = max( val[n-1]+solve(W-wt[n-1],wt,val,n-1),solve(W,wt,val,n-1));
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
      memset(dp,-1,sizeof(dp));
        return solve(W,wt,val,n);
       
    }
int main()
{
   int values[] = {1,2,3};
   int weight[] = {4,5,1};
   cout<<knapSack(3,weight,values,3)<<endl;
}