#include<iostream>
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
    if(p->data < key)
    {
        p->left = Rinserting(&p->left,key);
    }
    if(p->data > key)
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


Node* inserting(Node **q,int key)
{
    Node *p2 = NULL;
    Node * last2 = *q;
    Node *s2;
    if(last2 == NULL)
    {
        s2 = new Node;
        s2->data = key;
        s2->left = s2->right = NULL;
        return s2;

    }
    while(last2)
    {
        p2 = last2;
        if(last2->data > key)
        {
            last2 = last2->left;
        }
        else if(last2->data < key)
        {
            last2 = last2->right;
        }
    }
    s2 = new Node;
    s2->data = key;
    s2->left = s2->right = NULL;
    if(p2->data > key)
    {
        p2->left =s2;

    }
    else{
       p2->right = s2;
    }
    return p2;
}




bool areIdentical(Node * root1, Node *root2)
{
    /* base cases */
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    /* Check if the data of both roots is
    same and data of left and right
    subtrees are also same */
    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}


/* This function returns true if S
is a subtree of T, otherwise false */
bool isSubtree(Node *T, Node *S)
{
    /* base cases */
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    /* Check the tree with root as current Node */
    if (areIdentical(T, S))
        return true;

    /* If the tree with root as current
    Node doesn't match then try left
    and right subtrees one by one */
    return isSubtree(T->left, S) || isSubtree(T->right, S);
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

    Node * rt2 = NULL;
    int b[] = {34,48,50,66,77,88,90};
    int n1 = sizeof(b)/sizeof(int);
     i=0;
     rt2 = inserting(&rt2,b[i]);
    for( i=1;i<n1;i++)
    {
         inserting(&rt2,b[i]);
    }


    inorder(root);
    cout<<"NULL"<<endl;
    cout<<endl<<endl;
    inorder(rt2);
    cout<<"NULL"<<endl;
    return 0;
}
