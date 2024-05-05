#include<bits/stdc++.h>
using namespace std;
class Queue
{
  private:
      stack<int> stk1;
      stack<int> stk2;
  public:
    void enqueue(int value)
    {
        stk1.push(value);
    }
    int Front()
    {
        if(stk1.empty() and stk2.empty()){
            cout<<"queue is empty "<<endl<<endl;
            return -1;
        }
        if(stk2.empty()){
            while(! stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int value = stk2.top();
        return value;
    }
    void dequeue()
    {
        if(stk1.empty() and stk2.empty()){
            cout<<"queue is empty "<<endl<<endl;
            return;
        }
        Front();
        stk2.pop();
    }

};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.Front()<<endl;
    q.dequeue();
    cout<<endl<<q.Front()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<endl<<q.Front()<<endl;
    return 0;
}
