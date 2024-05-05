#include<iostream>
using namespace std;
//l points to the  first element of string and r point on the last element on the string
void permutate(string s , int l , int r)
{
    if(l==r)
    {
        cout<<s<<endl;
    }
    for(int i = l ; i < r; i++)
    {
        swap(s.at(l),s.at(i));
        permutate(s,l+1,r);
        swap(s.at(l),s.at(i));
    }
}
int main()
{
    string s ;
    cout<<" write down the string for permutate : "<<endl;
    getline(cin,s);
    int r = s.length();
    int l = 0;
    cout<<" after the permutation : "<<endl;
    permutate(s,l,r);
    cout<<s<<endl;
    return 0;
}
