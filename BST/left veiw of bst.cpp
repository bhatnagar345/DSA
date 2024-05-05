

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node * left;
    Node * right;
};


void printLeftView(Node* root)
{
    if (!root)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        // number of nodes at current level
        int n = q.size();

        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();

            // Print the left most element
            // at the level
            if (i == 1)
                cout<<temp->data<<" ";

            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);

            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
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

    printLeftView(root);

    return 0;
}

