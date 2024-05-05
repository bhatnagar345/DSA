/*MS Excel columns have a pattern like A, B, C, …, Z, AA, AB, AC, …., AZ, BA, BB, … ZZ, AAA, AAB …..
etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.
Given a column number, find its corresponding Excel column name. The following are more examples.

Input          Output
 26             Z
 51             AY
 52             AZ
 80             CB
 676            YZ
 702            ZZ
 705            AAC
*/
#include<iostream>
using namespace std;
string excel(int col)
{
    string ans = "";
    while(col>0)
    {
        int x = col%26;
        if(x==0)
        {
            ans = 'Z' + ans;
            col = (col/26)-1;
        }
        else{
            ans = char('A' + (x-1)) + ans;
            col = col/26;
        }
    }
    return ans;
}
int main()
{
    int col = 210;
    string res = excel(col);
    cout<<res<<endl;
    return 0;
}
