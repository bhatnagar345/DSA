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
    if(p->data > key)
    {
        p->lchild = Rinserting(&p->lchild,key);
    }
    if(p->data < key)
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


Node* inserting(Node **q,int key)
{
    Node *p = NULL;
    Node * last = *q;
    Node *s;
    if(last == NULL)
    {
        s = new Node;
        s->data = key;
        s->lchild = s->rchild = NULL;
        last = s;
        return last;
    }
    while(last)
    {
        p = last;
        if(last->data > key)
        {
            last = last->lchild;
        }
        else if(last->data < key)
        {
            last = last->rchild;
        }

    }
    s = new Node;
    s->data = key;
    s->lchild = s->rchild = NULL;
    if(p->data > key)
    {
        p->lchild =s;
    }
    else{
       p->rchild = s;
    }
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


    int b[] = {34,48,50,22,66,77,88,90};
    int n1 = sizeof(b)/sizeof(int);
    for( i=0;i<n1;i++)
    {
         inserting(&root,b[i]);
    }


    inorder(root);
    cout<<"NULL"<<endl;
    return 0;
}
