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

//function for removing the duplicates from unsorted array
void remov(Node **p)
{
    Node * first = *p;
    Node *prev = NULL;
    unordered_set<int>s;
    while(first != NULL)
    {
        if(s.find(first->data) != s.end())
        {
            prev->next = first->next;
            delete first;
        }
        else
        {
            s.insert(first->data);
            prev = first;
        }
        first = prev->next;
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

    int a[] = {1,5,3,4,5,6,5,8,5,5};
    int n = sizeof(a)/sizeof(int);
    create(root1,a,n);
    remov(&root1);
    display(root1);

    return 0;
}


