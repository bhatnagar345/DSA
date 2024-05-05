/*
Given a linked list where every node represents a linked list and contains two pointers of its type:
(i) Pointer to next node in the main list (we call it �right� pointer in the code below)
(ii) Pointer to a linked list where this node is headed (we call it the �down� pointer in the code below).
All linked lists are sorted. See the following example

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
Write a function flatten() to flatten the lists into a single linked list.
The flattened linked list should also be sorted. For example, for the above input list,
output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.
*/

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    int data;
    Node *next;
    Node *bottom;
};

//creating linked list using array
void create(Node *p,int a[], int n)
{
    Node * last;
    int x;
    //p = new Node;
    p->data = a[0];
    p->bottom = NULL;
    last = p;
    for(int i=1; i<n; i++)
    {
        Node *r = new Node;
        r->data = a[i];
        r->bottom= NULL;
        last->bottom = r;
        last = r;
    }
}



struct Node * merging(struct Node *first, struct Node * second)
{
    struct Node * third = NULL;
    struct Node *last = NULL;
    if(first->data < second->data)
    {
        last = first;
        third = last;
        first = first->bottom;                 
        last->bottom = NULL;
    }
    else
    {
        last = second;
        third = last;
        second = second->bottom;
        last->bottom = NULL;
    }
    while(first && second)
    {
        if(first->data < second->data)
        {
            last->bottom = first;
            last = first;
            first = first->bottom;
            last->bottom = NULL;
        }
        else
        {
            last->bottom = second;
            last = second;
            second = second->bottom;
            last->bottom = NULL;
        }
    }
    while(first)
    {
        last->bottom = first;
        last = first;
        first = first->bottom;
        last->bottom = NULL;
    }
    while(second)
    {
        last->bottom = second;
        last = second;
        second = second->bottom;
        last->bottom = NULL;
    }
    return third;
}
Node *flatten(Node *root)
{
    // Your code here
    root->next = merging(root->next, root->next->next);
    root = merging(root,root->next);
    return root;
}

void display(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    Node *q = p;
    do
    {
        cout<<p->data<<"->";
        p =p->bottom;
    }while(p!= NULL);
    cout<<"NULL";
    cout<<endl<<"|"<<endl;
    display(q->next);
}
void display1(Node *p)
{
    while(p)
    {
        cout<<p->data<<"->";
        p=p->bottom;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    int a[] = {5,7,8};
    int b[] = {6,10};
    int c[] = {9,11,12};
    int n1 = sizeof(a)/sizeof(int);
    int n2 = sizeof(b)/sizeof(int);
    int n3 = sizeof(c)/sizeof(int);
    Node *root1 = new Node;
    Node *root2 = new Node;
    Node *root3 = new Node;
    create(root1,a,n1);
    create(root2,b,n2);
    create(root3,c,n3);
    root1->next = root2;
    root2->next = root3;
    root3->next= NULL;
    cout<<"displaying the chain linked list : "<<endl;
    display(root1);
    Node * ans = flatten(root1);
    cout<<endl<<endl<<"after flattering the chain linked list : ";
    display1(ans);

    return 0;
}

