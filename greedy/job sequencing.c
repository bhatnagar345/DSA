#include<bits\stdc++.h>
using namespace std;
class job
{
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
