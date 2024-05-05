#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node * next;
} *first = NULL, * rear = NULL;
void  enqueue(int x)
{
    Node * t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL)
    {
        first = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}
int dequeue()
{
    if(first == NULL)
    {
        cout<<"the queue is empty "<<endl<<endl;
        return -1;
    }
    int x;
    Node * t = new Node;
    x = first->data;
    t = first;
    first = first->next;
    return x;
    delete t;
}
void display()
{
    Node * p = first;
    cout<<endl<<endl<<"queue is : ";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    enqueue(34);
    cout<<dequeue()<<endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    return 0;
}
