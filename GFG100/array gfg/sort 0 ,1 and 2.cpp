/*
Approach:The problem is similar to our old post Segregate 0s and 1s in an array, and both of these problems are variation of famous Dutch national flag problem.
The problem was posed with three colours, here `0′, `1′ and `2′. The array is divided into four sections:
a[1..Lo-1] zeroes (red)
a[Lo..Mid-1] ones (white)
a[Mid..Hi] unknown
a[Hi+1..N] twos (blue)
If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
If the element is 2 then swap it with an element in high range.
*/

 //Dutch national flag problem
#include<bits/stdc++.h>
using namespace std;
void sort012(int a[], int n)
{
        // coode here
        int low =0;
        int mid =0;
        int high =n-1;
        while(mid <= high)
        {
            switch(a[mid]){
                case 0:
                swap(a[mid++],a[low++]);
                break;
                case 1:
                mid++;
                break;
                case 2:
                swap(a[mid],a[high--]);
                break;
            }
        }

}

int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);
    for(auto elm : arr)
    {
        cout<<elm<<" ";
    }
    cout<<endl<<endl;
    return 0;
}
