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
    void postorder(Node *p);
    void postorder()
    {
        postorder(root);
    }
    void levelorder(Node *p);
    void levelorder()
    {
        levelorder(root);
    }
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

void tree::levelorder(Node *p)
{
    Node *t;
    Queue q(100);
    q.enqueue(p);
    cout<<endl<<endl<<"the levelorder traversal of the binary tree is : ";
    cout<<p->data<<"->";
    while(!q.isempty())
    {
        t = q.dequeue();
        if(t->lchild)
        {
            cout<<t->lchild->data<<"->";
            q.enqueue(t->lchild);
        }
        if(t->rchild)
        {
            cout<<t->rchild->data<<"->";
            q.enqueue(t->rchild);
        }
    }
    cout<<"NULL"<<endl;
}

void tree::postorder(Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<"->";
    }
}



int main()
{
    tree bt;
    bt.creating();
    bt.levelorder();
    cout<<endl<<endl<<"the postorder traversal of binary tree  : ";
    bt.postorder();
    cout<<"NULL"<<endl;
    return 0;
}
