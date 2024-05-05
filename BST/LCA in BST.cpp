/*Given values of two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). You may assume that both the values exist in the tree.

Examples:

Tree:


Input: LCA of 10 and 14
Output:  12
Explanation: 12 is the closest node to both 10 and 14
which is a ancestor of both the nodes.

Input: LCA of 8 and 14
Output:  8
Explanation: 8 is the closest node to both 8 and 14
which is a ancestor of both the nodes.

Input: LCA of 10 and 22
Output:  20
Explanation: 20 is the closest node to both 10 and 22
which is a ancestor of both the nodes.
*/

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
    else
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
        if(last->data > key)
        {
            last = last->lchild;
        }
        else if(last->data < key)
        {
            last = last->rchild;
        }
        else{
            return;
        }
    }
    s = new Node;
    s->data = key;
    s->lchild = s->rchild = NULL;
    if(p->data >key)
    {
        p->lchild =s;
        p=s;
    }
    else{
       p->rchild = s;
       p=s;
    }
}


Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   while(root)
   {
       if(root->data < n1 && root->data < n2)
       {
           root = root->rchild;
       }
       else if(root->data > n1 && root->data > n2)
       {
           root = root->lchild;
       }
       else{
           break;
       }
   }
   return root;
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
    cout<<"NULL"<<endl;

    int n3 ;
    int n4;
    cout<<endl<<endl<<"write down the two numbers for LCA : ";
    cin>>n3>>n4;
    Node * ans = LCA(root,n3,n4);
    cout<<endl<<endl<<"ans of the ques is : "<<ans->data<<endl;
    return 0;
}
