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

int count(Node *p)
{
    if(p == NULL)
    return 0;
    
    return count(p->next) +1;
}

int intersectPoint(Node*head1, Node*head2)
{
   int l1 = count(head1);
    int l2 = count(head2);
    Node* p,*q;
    int diff = 0;
    if(l1 >l2)
    {
        diff = l1 - l2;
        p = head1;
        q = head2;
    }
    if(l1 <l2)
    {
        diff = l2 - l1;
        p = head2;
        q = head1;
    }
    while(diff--)
    {
        p = p->next;
        if(p == NULL)
        return -1;
    }
    
    while(p and q)
    {
        if(p == q)
        return p->data;
        
        if( p == NULL)
        return -1;
        if( q == NULL)
        return -1;
        
        p = p->next;
        q = q->next;
    }
    return -1;
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
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(int);
    int b[] = {12,32,12,7,8,9,10};
    int n2 = sizeof(b)/sizeof(int);
    create(root1,a,n);
    create(root2,b,n2);
    cout<<endl<<endl<<"the first list is : ";
    display(root1);
    cout<<endl<<endl<<"the second list is : ";
    display(root2);
    int ans = intersectPoint(root1,root2);
    cout<<endl<<endl<<"the intersecting point in two linked list is : "<<ans<<endl;
    return 0;
}

