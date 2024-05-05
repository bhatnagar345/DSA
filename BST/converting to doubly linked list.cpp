
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node * left;
    Node * right;
};

Node * Rinserting(Node **q,int key)
{
    Node *p = *q;
    Node *t = NULL;
    if(p == NULL)
    {
        t= new Node;
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }
    if( p->data > key )
    {
        p->left = Rinserting(&p->left,key);
    }
    if(p->data < key)
    {
        p->right = Rinserting(&p->right,key);
    }
    return p;
}


void inorder(Node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<"->";
        inorder(p->right);
    }
}

void makingDLL(Node * root, Node * &head, Node * &prev, int &flag)
{
    if(!root)
    {
        return;
    }
    makingDLL(root->left,head,prev,flag);
    if(flag==0)
    {
        head = root;
        prev = root;
        flag = 1;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    makingDLL(root->right,head,prev,flag);
}
Node * bToDLL(Node *root)
{
    // your code here
    Node *head = NULL;
    Node *prev = NULL;
    int flag = 0;
    makingDLL(root,head,prev,flag);
    head->left = NULL;
    return head;
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

       cout<<endl<<endl;
    inorder(root);
    cout<<"NULL"<<endl<<endl;

    Node *dLL = bToDLL(root);
    while(dLL){
        cout<<dLL->data<<" ";
        dLL = dLL->right;
    }
    cout<<endl<<endl;

    return 0;
}
