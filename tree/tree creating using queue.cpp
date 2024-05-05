#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node * rchild;
};
class Queue
{
private:
    int first;
    int rear;
    Node **q;
    int Size;
public:
    Queue()
    {
        Size = 10;
        first = rear =-1;
        q = new Node*[Size];
    }
    Queue(int n)
    {
        Size = n;
        first = rear =-1;
        q = new Node*[Size];
    }
    bool isempty();
    void enqueue(Node *x);
    Node * dequeue();
};
bool Queue ::isempty()
{
    if(first == rear)
    {
        return 1;
    }
    return 0;
}

void Queue::enqueue(Node *x)
{
    if(rear == Size)
    {
        cout<<"Queue is Full"<<endl;
        return ;
    }
    rear++;
    q[rear] = x;
}
Node * Queue ::dequeue()
{
    Node *e;
    if(isempty())
    {
        cout<<"Queue is empty "<<endl;
        return NULL;
    }
    first++;
    e = q[first];
    return e;
}

class tree
{
private:
    Node *root;
public:
    tree()
    {
        root = NULL;

    }
    void creating();
};

void tree::creating()
{
    Node *p,*t;
    int x;
    Queue q(100);
    cout<<"Write down the root value : ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while(! q.isempty())
    {
        p = q.dequeue();
        cout<<endl<<endl<<"Write down the "<<p->data<<" left child : ";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild =t;
            q.enqueue(t);
        }
         cout<<endl<<endl<<"Write down the "<<p->data<<" rigth child : ";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild =t;
            q.enqueue(t);
        }
    }
}





int main()
{
    tree bt;
    bt.creating();
    return 0;
}
