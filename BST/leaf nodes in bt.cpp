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
    int leafNode(Node *p);
    int leafNode()
    {
        leafNode(root);
    }
    int oneleafNode(Node *p);
    int oneleafNode()
    {
        oneleafNode(root);
    }
    int nonleaf(Node *p);
    int nonleaf()
    {
        nonleaf(root);
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


int tree::leafNode(Node *p)
{
    int x,y;
    if(p)
    {
        x = leafNode(p->lchild);
        y = leafNode(p->rchild);
        if(p->lchild == NULL && p->rchild == NULL)
        {
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}

int tree::nonleaf(Node *p)
{
    int x,y;
    if(p)
    {
        x = nonleaf(p->lchild);
        y = nonleaf(p->rchild);
        if(p->lchild == NULL && p->rchild == NULL)
        {
            return x+y;
        }
        else{
            return x+y+1;
        }
    }
    return 0;
}


int tree::oneleafNode(Node *p)
{
    int x,y;
    if(p)
    {
        x = oneleafNode(p->lchild);
        y = oneleafNode(p->rchild);
        if((p->lchild != NULL && p->rchild == NULL)||(p->lchild == NULL && p->rchild != NULL))
        {
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}




int main()
{
    tree bt;
    bt.creating();

    cout<<endl<<endl<<"the total leaf nodes in Binary tree : "<<bt.leafNode()<<endl;

    cout<<endl<<endl<<"the total NON leaf nodes in Binary tree : "<<bt.nonleaf()<<endl;

    cout<<endl<<endl<<"the total  leaf nodes with only one degree in Binary tree : "<<bt.oneleafNode()<<endl;
    return 0;
}

