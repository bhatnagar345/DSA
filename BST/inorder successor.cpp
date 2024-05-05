#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node * lchild;
    Node * rchild;
    Node *next;
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
Node * previous = NULL;
void inorderSuccesor(Node*p)
{
    Node * prev = previous;
    if(p==NULL)
    {
        return;
    }
    if(p)
    {
     inorderSuccesor(p->lchild);
     if(prev != NULL){
        prev->next = p;
     }
     prev = p;
     inorderSuccesor(p->rchild);
    }
}
void inorderSuccesorTraversal(Node *p)
{
    while(previous){
        cout<<previous->data<<endl;
        previous = previous->next;
    }
}



int main()
{
    Node * root = NULL;
    int a[] = {3,5,21,7,6,24,45,8,34,48,50,66,77,88,90};
    int n = sizeof(a)/sizeof(int);
    int i=0;
    root = Rinserting(&root,a[i]);
    for( i=1; i<n; i++)
    {
        Rinserting(&root,a[i]);
    }


    inorder(root);
    cout<<"NULL"<<endl<<endl;

    inorderSuccesor(root);

    inorderSuccesorTraversal(root);
    cout<<"NULL"<<endl;

    return 0;
}
