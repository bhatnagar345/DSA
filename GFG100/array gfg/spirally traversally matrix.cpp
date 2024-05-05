/*
Spirally traversing a matrix
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>&matrix,int r, int c)
{
     int left =0,right = c-1,top =0,bottom = r-1;
     int div =0;
     while(top <= bottom && left <= right)
     {
         if(div ==0)
         {
             for(int i=left ; i <= right ; i++)
             {
                 cout<<matrix[top][i]<<" ";
             }
           div =1;
           top++;
         }
         else if(div ==1)
         {
             for(int i=top ; i<= bottom;i++)
             {
                 cout<<matrix[i][right]<<" ";
             }
           div =2;
           right--;
         }
         else if(div ==2)
         {
             for(int i=right ; i>= left;i--)
             {
                 cout<<matrix[bottom][i]<<" ";
             }
           div =3;
           bottom--;
         }
         else if(div ==3)
         {
             for(int i=bottom ; i>= top;i--)
             {
                 cout<<matrix[i][left]<<" ";
             }
           div =0;
           left++;
         }
     }
     cout<<endl<<endl;

}
int main()
{
    vector<vector<int>>matrix = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}};
    solve(matrix,4,4);
    return 0;
}
