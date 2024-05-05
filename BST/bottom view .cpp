

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node * left;
    Node * right;
};


void printbottomView(Node* root)
{
    if (!root)
        return;

    queue<pair<Node*,int>> q;
    q.push({root,0});
    map<int,int>h;
    while (!q.empty())
    {
        // number of nodes at current level
        Node * t= q.front().first;
        int l = q.front().second;
        h[l] =  t->data;
        if(t->left) q.push({t->left,l-1});
        if(t->right) q.push({t->right,l+1});
    }
    for(auto el : h)
    {
        cout<<el.second<<" ";
    }
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

    printbottomView(root);

    return 0;
}

