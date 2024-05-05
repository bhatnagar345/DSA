/*The diameter of a tree (sometimes called the width) is the number of nodes
on the longest path between two end nodes. The diagram below shows two trees
each with diameter nine, the leaves that form the ends of the longest path
are shaded (note that there is more than one path in each tree of length nine,
but no path longer than nine nodes).*/

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

int height(Node *p)
{
    int x=0,y=0;
    if(p== NULL)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    if(x>y)
    {
        return x+1;
    }
    else{
        return y+1;
    }
}


int diameter(Node *p)
{
    if(p== NULL)
    {
        return 0;
    }
    int lheight , rheight;
    int ldiameter, rdiameter;
    lheight = height(p->lchild);
    rheight = height(p->rchild);
    ldiameter = diameter(p->lchild);
    rdiameter = diameter(p->rchild);

    return max(lheight + rheight +1 , max(ldiameter,rdiameter));
}





int main()
{
    Node * root = NULL;
    int a[] = {3,5,21,7,6,24,45,8,34,48,50,66,77,88,90};
    int n = sizeof(a)/sizeof(int);
    int i=0;
    root = Rinserting(&root,a[i]);
    for( i=1;i<n;i++)
    {
         Rinserting(&root,a[i]);
    }


   /* int b[] = {34,48,50,66,77,88,90};
    int n1 = sizeof(b)/sizeof(int);
     i=0;
    for( i=0;i<n;i++)
    {
         inserting(&root,b[i]);
    }*/


    inorder(root);
    cout<<"NULL"<<endl;

    cout<<endl<<endl<<"the height of the tree is : "<<height(root)<<endl;

    cout<<endl<<endl<<"diameter of the tree is : "<<diameter(root)<<endl;
    return 0;
}
