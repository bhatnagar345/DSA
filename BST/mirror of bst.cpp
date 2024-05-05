#include<bits/stdc++.h>
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


void preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<"->";
        preorder(p->lchild);

        preorder(p->rchild);
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

void mirror(Node *node)
{
    if(node == NULL)
    {
        return ;
    }
    queue<Node*>q;
    q.push(node);
    Node *p;
    while(! q.empty())
    {
        p = q.front();
        q.pop();
        Node* temp = p->lchild;
        p->lchild = p->rchild;
        p->rchild = temp;
        if(p->lchild)
        {
            q.push(p->lchild);
        }
        if(p->rchild)
        {
            q.push(p->rchild);
        }

    }
}



void Rmirror(Node* node) {
        // code here
        if(node == NULL)
        {
            return ;
        }
        Rmirror(node->lchild);
        Rmirror(node->rchild);
        Node* temp = node->lchild;
        node->lchild = node->rchild;
        node->rchild = temp;
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


    preorder(root);
    cout<<"NULL"<<endl;

    cout<<endl<<endl<<"After mirroring the BST : ";

    mirror(root);

    preorder(root);
    cout<<"NULL"<<endl;


    cout<<endl<<endl<<"After mirroring the mirrored BST : ";
    Rmirror(root);

    preorder(root);
    cout<<"NULL"<<endl;
    return 0;
}

