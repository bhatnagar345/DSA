

#include<iostream>
using namespace std;
void twoOddNum(int Arr[], int N)
    {
        // code here
        int first =0, second=0;
        int xo = Arr[0];
        int right;
        for(int i=1;i<N;i++)
        {
            xo = xo^ Arr[i];
        }
        right = xo & ~(xo-1);
        for(int i = 0; i<N;i++)
        {
            if(right & Arr[i])
            {
                first ^= Arr[i];
            }
            else
            {
                second ^= Arr[i];
            }
        }
        cout<<first<<" "<<second<<endl;
    }

int main()
{
    int a[] = {1,2,3,2,4,4};
    int n = sizeof(a)/sizeof(int);
    twoOddNum(a,n);
    return 0;
}
