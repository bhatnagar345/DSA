/*Given an array containing only 0s and 1s, find the largest subarray which contains equal no of 0s and 1s. The expected time complexity is O(n).
Examples:

Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
Output: 1 to 6
(Starting and Ending indexes of output subarray)

Input: arr[] = {1, 1, 1, 1}
Output: No such subarray

Input: arr[] = {0, 0, 1, 1, 0}
Output: 0 to 3 Or 1 to 4*/

#include<iostream>
using namespace std;
 void longsub(int a[],int n)
 {
     int left,right;
     int sum ;
     for(int i=0;i<n;i++)
     {
         if(a[i]==0)
         {
             a[i] = -1;
         }
     }
     int len = 0;
     for(int i=0;i<n;i++)
     {
         sum =0;
         for(int j=i;j<n;j++)
         {
             sum += a[j];
             if(sum ==0 && len < (j-i+1) )
             {
                 left = i+1;
                 right = j+1;
                 len = j-i+1;
             }
         }
     }
     if(len==0)
     {
         cout<<"there is no subarray "<<endl;
         return;
     }
     else
     {
         cout<<"the longest subarray is : "<<left<<" to "<<right<<endl;
         cout<<"and length of subarray is : "<<len<<endl;
     }
 }

 int main()
 {
     int a[]={1,0,0,0,1,1,1,1,1};
     int n = sizeof(a)/sizeof(int);
     longsub(a,n);
     return 0;
 }
