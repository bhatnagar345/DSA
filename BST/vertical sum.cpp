/*
Given a Binary Tree, find the vertical sum of the nodes
that are in the same vertical line. Print all sums through different
vertical lines.

Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7
*/


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

map<int,int>hasha;
map<int,int>:: iterator it;
void sum(Node * p, int hd)
{
    if(p == NULL)
    {
        return ;
    }
    if(p)
    {
      sum(p->lchild, hd-1);
    hasha[hd] += p->data;
    sum(p->rchild, hd+1);
    return;
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

     sum(root,0);
     for(auto elm : hasha)
     {
         cout<<elm.second<<endl;
     }

    return 0;
}
