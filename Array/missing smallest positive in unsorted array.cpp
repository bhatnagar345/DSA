/*You are given an unsorted array with both positive and negative elements.
You have to find the smallest positive number missing from the array in O(n) time
using constant extra space. You can modify the original array.

Examples

 Input:  {2, 3, 7, 6, 8, -1, -10, 15}
 Output: 1

 Input:  { 2, 3, -7, 6, 8, 1, -10, 15 }
 Output: 4

 Input: {1, 1, 0, -1, -2}
 Output: 2
 */

 #include<iostream>
 using namespace std;
 int unsortedsmallest(int a[],int n)
 {
     bool small[n+1]={false};
     for(int i=0;i<n;i++)
     {
         if(a[i]>0 && a[i]<n)
         {
             small[a[i]]++;
         }
     }
     for(int i=1;i<n;i++)
     {
         if(!small[i])
         {
             return i;
         }
     }
     return -1;
 }
 int main()
 {
     int a[] = {2,3,1,-1,4,3,6,5};
     int n = sizeof(a)/sizeof(int);
     int b[1];
      b[0] = unsortedsmallest(a,n);
     cout<<b[0]<<endl;
     return 0;
 }
