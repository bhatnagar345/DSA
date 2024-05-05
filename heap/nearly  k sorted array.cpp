#include <bits/stdc++.h>
using namespace std;
void print_arr(int a[],int n){
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Nsorted(int a[],int n, int k){
    priority_queue<int, vector<int>,greater<int>>q(a,a+k+1);
    int index = 0;
    for(int i=k+1;i<n;i++){
        a[index++] = q.top();
        q.pop();
        q.push(i);
    }
    while(!q.empty()){
      a[index++] = q.top();
        q.pop();
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	     if(k<=n){
        sort(a,a+n);
        print_arr(a,n);

        }
        else{
	    Nsorted(a,n,k);
        }
	}
	return 0;
}
