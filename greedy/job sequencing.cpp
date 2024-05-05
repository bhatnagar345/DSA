/*
Given an array of jobs where every job has a deadline and associated profit
if the job is finished before the deadline. It is also given that every job
takes a single unit of time, so the minimum possible deadline for any job is 1.
How to maximize total profit if only one job can be scheduled at a time.

Examples:

Input: Four Jobs with following
deadlines and profits
JobID  Deadline  Profit
  a      4        20
  b      1        10
  c      1        40
  d      1        30
Output: Following is maximum
profit sequence of jobs
        c, a


Input:  Five Jobs with following
deadlines and profits
JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15
Output: Following is maximum
profit sequence of jobs
        c, a, e
*/

#include<bits/stdc++.h>
using namespace std;
class job
{
public:
        char id;
    int deadline;
    int profit;
};
bool compare(job a, job b)
{
    return(a.profit > b.profit);
}
int total_profit(job arr[] , int n)
{
    bool slot[n] = {false};
    int ans = 0;   
    sort(arr , arr+n, compare);
    for(int i=0 ; i< n;i++)
    {
        for(int j = min(n,arr[i].deadline)-1 ; j>=0 ; j--){
            if(slot[j] == false){
                slot[j] = true;
                ans = ans + arr[i].profit;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},{'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int total_pro = total_profit(arr,n);
    cout<<endl<<endl<<"the total profit earned  is : "<<total_pro<<endl;
    return 0;
}
