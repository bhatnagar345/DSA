#include<bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int top;
    queue<int>q1;
    queue<int>q2;
public:
    Stack()
    {
       top=0;
    }

    void pushu(int n)
    {
        top++;
        q2.push(n);
        while(! q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void popu()
    {
        top--;
        cout<<q1.front<<endl;
         q1.pop();
    }

    void display()
    {
      while(!q1.empty())
      {
          cout<<q1.front()<<"->";
          q1.pop();
      }
      cout<<"NULL"<<endl;
    }
};

int main()
{
    Stack stk;
    stk.pushu(1);
    stk.pushu(2);
    stk.pushu(3);
    stk.pushu(4);
    stk.pushu(5);
    stk.pushu(6);
    stk.pushu(7);
    stk.popu();
    stk.display();
    return 0;
}
