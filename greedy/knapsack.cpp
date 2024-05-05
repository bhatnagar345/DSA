#include<bits/stdc++.h>
using namespace std;
struct product{
    int value;
    int weight;
};
bool compare(struct product a ,struct product b)
{
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return (r1 > r2);
}
int fractionalKnapsack(struct product a[],int n, int w)
{
    int ans =0 ;
    sort(a,a+n,compare);
    int i;
    for( i=0; i<n;i++){
        if(w >= a[i].weight && w>0){
            ans = ans + a[i].value;
            w = w - a[i].weight;
        }
        else{
            break;
        }
    }

    if(w>0){

        ans = ans + (a[i].value)*((double)w/(double)a[i].weight);
    }
    return ans;
}
int main()
{
    int w = 50;
    product arr[]={
    {60,10},{100,20},{120,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<endl<<endl<<"the maximum profit of is  : "<<fractionalKnapsack(arr,n,w)<<endl<<endl;
    bool slot[5] = {false};
    for(auto elm : slot){
        cout<<endl<<elm;
    }
    return 0;
}
