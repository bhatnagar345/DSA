/*
Largest Number formed from an Array
Medium Accuracy: 50.0% Submissions: 19567 Points: 4
Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.


Example 1:

Input:
N = 5
Arr[] = {3, 30, 34, 5, 9}
Output: 9534330
Explanation: Given numbers are {3, 30, 34,
5, 9}, the arrangement 9534330 gives the
largest value.
*/

#include<bits/stdc++.h>
using namespace std;
int myCompare(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1 : 0;
}
int main()
{
    vector<string>Arr = {"3", "30", "34", "5", "9"};
    sort(Arr.begin(),Arr.end(),myCompare);
    cout<<"Largest number formed by array is : ";
    for(int i=0;i<Arr.size();i++)
    {
        cout<<Arr[i];
    }
    cout<<endl<<endl;
    vector<string>vec;
    string n = "";
    n += 9;
    n += "harsh";
    vec.push_back(n);
    cout<<vec[0]<<endl;
    return 0;
}
