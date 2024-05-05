









#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node * left;
    Node * right;
};

void RightViewAns(Node *root, int level , int &maxlevel)
{
    if(root == NULL){
        return;
    }
    if(maxlevel < level){
        cout<<root->data<<" ";
        maxlevel = level;
    }
    RightViewAns(root->right, level +1, maxlevel);
    RightViewAns(root->left,level +1, maxlevel);
}

void rightview(Node * root)
{
    int maxlevel = 0;
    RightViewAns(root,1,maxlevel);
}


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
    if(p->data > key)
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

    cout<<"The right view of the BST : ";
    rightview(root);
    cout<<endl<<endl;

    return 0;
}


