#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int mini =0;
int getmin()
{
    if(s.empty())
    {
        return -1;
    }
    else{
        return mini;
    }
}
int pop()
{
    if(s.empty())
        return -1;
    else if(s.top() >= mini)
    {
        int x = s.top();
        s.pop();
        return x;
    }
    else
    {
        int x = mini;
        mini = 2*s.top() - x;
        s.pop();
        return x;
    }
}
void push(int x)
{
    if(s.empty())
    {
        mini = x;
        s.push(x);
    }
    else if(x >= mini)
    {
        s.push(x);
    }
    else{
        s.push(2*x -mini);
        mini =x;
    }
}

int main()
{
    push(2);
   push(3);
   cout<<pop()<<endl;
   cout<<getmin()<<endl;
   push(1);
   cout<<getmin()<<endl;

}