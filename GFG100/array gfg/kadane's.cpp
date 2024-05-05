#include<iostream>
using namespace std;
class Kadanes{
public:
    int subarray(int ar[],int n)
    {
        int max=0,sum=0,ab=-1;
        for(int i=0;i<n;i++)
        {
            sum = sum+ar[i];
            if(sum<0){
                sum=0;
            }
            if(max<sum){
                max=sum;
            }
        }
        if(max<0){
         return ab;
        }
        else{
            return max;
        }
    }
};
    int main()
    {
        int a[5];
        for(int i=0;i<5;i++)
        {
            cin>>a[i];
        }
        Kadanes ans;
        cout<<ans.subarray(a,5)<<endl;
        return 0;
    }
