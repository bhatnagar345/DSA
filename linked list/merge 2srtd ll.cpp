#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    int data;
    Node *next;
}*root1 = NULL;

//creating linked list using array
void create(Node *p,int a[], int n)
{
    Node * last;
    int x;
    //p = new Node;
    p->data = a[0];
    p->next = NULL;
    last = p;
    for(int i=1; i<n; i++)
    {
        Node *r = new Node;
        r->data = a[i];
        r->next= NULL;
        last->next = r;
        last = r;
    }
}
Node *third = NULL;
//function for merging the 2 sorted ll
void merging(Node **p,Node **q)
{
    Node *first = *p;
    Node *second = *q;
    Node *last = NULL;
    if(first->data < second->data)
    {
        last = first;
        third = last;
        first = first->next;
        last->next = NULL;
    }
    else{
        last = second;
        third = last;
        second = second->next;
        last->next = NULL;
    }
    while(first && second)
    {
        if(first->data < second->data)
    {
        last->next = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    else{
        last->next = second;
        last = second;
        second = second->next;
        last->next = NULL;
    }
    }
    while(first)
    {
       last->next = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    while(second)
    {
        last->next = second;
        last = second;
        second = second->next;
        last->next = NULL;
    }
}



void display(Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}


int main()
{
    root1 = new Node;
     Node *root2 = new Node;
    int a[] = {1,3,5,7,9};
    int n = sizeof(a)/sizeof(int);
    int b[] = {2,4,6,8,10};
    int n2 = sizeof(b)/sizeof(int);
    create(root1,a,n);
    create(root2,b,n2);
    cout<<endl<<endl<<"the first list is : ";
    display(root1);
    cout<<endl<<endl<<"the second list is : ";
    display(root2);

     merging(&root1,&root2);
     cout<<endl<<endl<<"After merging the two linked lists : ";
    display(third);

    return 0;
}


