#include<iostream>
using namespace std;
int atoi(char c[],int n)
{
    int i=0;
    int sign = 1;
    int res =0;
    if(c[0] == '-')
    {
        sign = -1;
        i++;
    }
    for(i;c[i] != '/0';++i)
    {
        res = res*10 + c[i] - '0';
    }
    return res*sign;
}
int main()
{
    char c[] = "-123";
    int n = sizeof(c)/sizeof(char);
    int num = atoi(c,n);
    cout<<num<<endl;
    return 0;
}
