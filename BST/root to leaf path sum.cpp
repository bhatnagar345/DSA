/*Given a binary tree and a number, return true if the tree has a root-to-leaf path such that
adding up all the values along the path equals the given number.
Return false if no such path can be found.
            10
            / \
            8   2
           / \ /
           3 5 2



For example, in the above tree root to leaf paths exist with following sums.
21 �> 10 � 8 � 3
23 �> 10 � 8 � 5
14 �> 10 � 2 � 2
So the returned value should be true only for numbers 21, 23 and 14. For any other number, returned value should be false.*/

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

bool hasPathSum(Node *root, int S)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        bool ans =0;
        int sub = S - root->data;
        if(sub == 0 && root->lchild == NULL && root->rchild == NULL)
        {
            return 1;
        }
        if(root->lchild)
        {
            ans = ans || hasPathSum(root->lchild,sub);
        }
        if(root->rchild)
        {
            ans = ans|| hasPathSum(root->rchild,sub);
        }
        return ans;
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
        cout<<"NULL"<<endl;

       // cout<<endl<<endl<<"the height of the tree is : "<<height(root)<<endl;

        cout<<endl<<endl<<"root to leaf path sum  is there in tree : "<<hasPathSum(root,77)<<endl;
        return 0;
    }
