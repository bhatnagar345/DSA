#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node * lchild;
    Node * rchild;
};

Node * Rinserting(Node **q,int key)
{
    Node *p = *q;
    Node *t = NULL;
    if(p == NULL)
    {
         t= new Node;
         t->data = key;
         t->lchild = t->rchild = NULL;
         return t;
    }
    if(p->data < key)
    {
        p->lchild = Rinserting(&p->lchild,key);
    }
    if(p->data > key)
    {
       p->rchild = Rinserting(&p->rchild,key);
    }
    return p;
}


void inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<"->";
        inorder(p->rchild);
    }
}


void inserting(Node **q,int key)
{
    Node *p;
    Node * last = *q;
    Node *s;
    if(p == NULL)
    {
        s = new Node;
        s->data = key;
        s->lchild = s->rchild = NULL;
        last = s;
    }
    while(last)
    {
        p = last;
        if(last->data < key)
        {
            last = last->lchild;
        }
        else
        {
            last = last->rchild;
        }
    }
    s = new Node;
    s->data = key;
    s->lchild = s->rchild = NULL;
    if(p->data <key)
    {
        p->lchild =s;
        p = s;
    }
    else{
       p->rchild = s;
       p = s;
    }
}


void deleting(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    deleting(p->lchild);
    deleting(p->rchild);
    cout<<endl<<endl<<"deleting the node which have data : "<<p->data;
    delete p;
}





int main()
{
    Node * root = NULL;
    int a[] = {3,5,21,7,6,24,45,8};
    int n = sizeof(a)/sizeof(int);
    int i=0;
    root = Rinserting(&root,a[i]);
    for( i=1;i<n;i++)
    {
         Rinserting(&root,a[i]);
    }


    int b[] = {34,48,50,66,77,88,90};
    int n1 = sizeof(b)/sizeof(int);
     i=0;
    for( i=0;i<n;i++)
    {
         inserting(&root,b[i]);
    }


    inorder(root);

    deleting(root);
    cout<<"NULL"<<endl;
    return 0;
}
