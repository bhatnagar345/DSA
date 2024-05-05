#include<bits/stdc++.h>
using namespace std;
class C_Queue
{
public:
    int qfront;
    int rear;
    int qsize;
    int *q;
    C_Queue()
    {
        qsize = 10;
        qfront = rear = 0;
        q = new int[qsize];
    }
    C_Queue(int n)
    {
        qsize = n;
        rear = qfront = 0;
        q = new int[qsize];
    }
    void enqueue(int value)
    {
        if((rear+1)%qsize == qfront){
            cout<<"the queue is full queue can't take this value : "<<value<<endl<<endl<<endl;
            return;
        }
        else{
            rear = (rear+1)%qsize;
            q[rear] = value;
        }
    }
    void dequeue()
    {
        if(rear == qfront){
            cout<<"the queue is empty "<<endl;
            return;
        }
        else{
            qfront = (qfront+1)%qsize;

        }
    }
    int top(){
     if(rear == qfront){
            cout<<"the queue is empty "<<endl;

        }
        else{
         int x = q[(qfront+1)%qsize];
         return x;
        }
    }
    void display()
    {
        int i = (qfront +1)%qsize;
        cout<<endl<<endl<<"the queue is : ";
        do{
            cout<<q[i]<<" ";
            i = (i+1)%qsize;
        }while( i != (rear +1)%qsize);
        cout<<endl<<endl;
    }
};
int main()
{
    C_Queue harsh(10);
    harsh.enqueue(1);
    harsh.enqueue(2);
    harsh.enqueue(3);
    harsh.enqueue(4);
    harsh.enqueue(5);
    harsh.enqueue(6);
    harsh.enqueue(7);
    harsh.enqueue(8);
    harsh.enqueue(9);
    harsh.enqueue(10);
    harsh.enqueue(11);
    harsh.enqueue(12);
    harsh.display();
    cout<<"the dequeue value is : "<<harsh.top()<<endl;
    harsh.dequeue();
    harsh.display();
    return 0;
}
