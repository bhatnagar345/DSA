#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
}*root = NULL;

void create(Node *p,int a[],int n)
{
    Node *last, *q;
    p->data = a[0];
    p->next = p;
    last = p;
    for(int i=1;i<n;i++)
    {
        q = new Node;
        q->data = a[i];
        q->next = last->next;
        last->next = q;
        last = q;
    }
}

//function for sorted insert in circular insert
void sinsert(Node **head,int x)
{
    Node *p = *head;
    Node *q,*t;
    t = new Node;
    t->data = x;
    t->next=t;
    if(t->data < p->data)
    {
        t->next = p;
        while(p->next!= *head)
        {
            p = p->next;
        }
        p->next = t;
        *head = t;
        return;
    }
    p = *head;
    while(p->next != *head)
    {
        q = p;
        p = p->next;
        if(p->data > x)
        {
            q->next = t;
            t->next = p;
            return;
        }
    }
    p->next = t;
    t->next = *head;
    return;
}

void display(Node *head)
{
    Node * p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!= head);
    cout<<endl<<endl;
}

int main()
{
    root = new Node;
    int a[] = {2,3,4,5,7,8,9,10};
    int n = sizeof(a)/sizeof(int);
    cout<<"circular linked list is : ";
    create(root,a,n);
    display(root);


    cout<<endl<<endl<<"inserting the element in sorted linked list : ";
    sinsert(&root,1);
    display(root);

    cout<<endl<<endl<<"inserting the element in sorted linked list : ";
    sinsert(&root,11);
    display(root);

    cout<<endl<<endl<<"inserting the element in sorted linked list : ";
    sinsert(&root,6);
    display(root);
    return 0;
}
