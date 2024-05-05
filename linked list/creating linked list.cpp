#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    int data;
    Node *next;
}*root = NULL;
int coun(Node *p);
void display(Node *p);
//deleting elements from node
void del(Node **pt, int index);

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

//insert at tail
void insertail(Node **p, int key)
{
    Node *pt = *p;
    Node *n = new Node;
    n->data = key;
    n->next = NULL;
    for(int i=0; i< (coun(*p)-1); i++)
    {
        pt=pt->next;
    }
    pt->next =n;
}

//inserting the key at nth position
void inser(Node **p, int index, int key)
{
    if(index > coun(*p))
    {
        cout<<endl<<endl<<"Not possible"<<endl;
    }
    Node *l= *p;
    Node *pt = new Node;
    pt->data = key;
    pt->next = NULL;
    if(index == 1)
    {
        pt->next = *p;
        *p = pt;
    }
    for(int i=0; i<index-2; i++)
    {
        l = l->next;
    }
    pt->next = l->next;
    l->next = pt;
}

//function for removing the duplicate element
Node * remdupli(Node **head)
{

     // your code goes here
     map<int,int>m;
     Node * curr = *head;
     m[curr->data] =1;
     Node * prev = curr;
     curr = curr->next;
     while(curr)
     {
         if(m[curr->data])
         {
             prev->next = curr->next;
             delete(curr);
         }
         else{
             m[curr->data] = 1;
             prev = curr;
         }
         curr = prev->next;
     }
     return *head;

    cout<<endl<<endl<<"after removing the duplicates : ";
}

int sum(Node *p)
{
    int sum =0;
    if(p==NULL)
    {
        return 0;
    }
    while(p)
    {
        sum = sum +p->data;
        p=p->next;
    }
    return sum;
}

//count the node function
int coun(Node*p)
{
    int total =0;
    if(p==NULL)
    {
        return 0;
    }
    while(p)
    {
        total++;
        p=p->next;
    }
    return total;
}

//recursive sum
int rsum(Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    return rsum(p->next) + p->data;
}

//recursive count
int rcoun(Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    return rcoun(p->next) +1;
}

//deleting elements from node
void del(Node **pt, int index)
{
    int x;
    Node *p = *pt;
    Node*l =NULL;
    if(index<=0 || index> coun(*pt))
    {
        cout<<"the index is wrong :"<<endl;;
    }
    if(index == 1)
    {
        Node * temp = *pt;
        *pt = temp->next;

        delete temp;

    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            l=p;
            p=p->next;
        }
        l->next = p->next;
        x= p->data;
        delete p;
    }
}

//function for reverse the array
void rev(Node **p)
{
    Node *r = NULL;
    Node *s = NULL;
    Node *q = *p;
    while(q)
    {
        s =r;
        r = q;
        q = q->next;
        r->next = s;
    }
    *p = r;
}

//function for sorted insert in linked list
void sortedInsert( Node** head, int data) {
        // Code here
         Node * p = new Node;
         p->data = data;
         p->next = NULL;
         Node *last = *head;
        if(last->data > p->data)
        {
            p->next = last;
            last  = p;
            return;
        }
        while(last->next)
        {
            if(last->next->data > p->data)
            {
                p->next = last->next;
                last->next = p;
                last = p;
                return;
            }
            last = last->next;
        }
        last->next = p;
        last = p;
    }


//function for displaying the linked list
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
    root = new Node;
    int a[]= {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(int);
    create(root,a,n);
    display(root);
    int su = rsum(root);
    cout<<"the sum of the all nodes is : "<<su<<endl;

    int cou= rcoun(root);
    cout<<endl<<endl<<"the total no. of nodes is : "<<cou<<endl;

    int inde = 1;
    del(&root,inde);
    cout<<endl<<endl<<"after deleting the value at "<< inde <<" the list is : ";
    display(root);

    cou= rcoun(root);
    cout<<endl<<endl<<"the total no. of nodes is : "<<cou<<endl;

    int index = 8;

    inser(&root,index,1);
    cout<<endl<<endl<<"inserting the element 1 in index "<<index<<" : "<<endl;

    index = 1;

    inser(&root,index,1);
    cout<<endl<<endl<<"inserting the element 1 in index "<<index<<" : ";

    display(root);
    cou= rcoun(root);
    cout<<endl<<endl<<"the total no. of nodes is : "<<cou<<endl;


    int h = 10;
    insertail(&root,10);
    cout<<endl<<endl<<"after inserting "<<h<<" at the end : ";
    display(root);

    insertail(&root,10);
    cout<<endl<<endl<<"after inserting "<<h<<" at the end : ";
    display(root);


    h = 11;
    insertail(&root,10);
    cout<<endl<<endl<<"after inserting "<<h<<" at the end : ";

    display(root);

    sortedInsert(&root, 6);
    cout<<endl<<endl<<"after inserting the 6 in sorted list : ";
    display(root);

    rev(&root);
    cout<<endl<<endl<<" after reversing the linked list : ";
    display(root);

    //remDupli(&root);
    //display(root);
    delete root;
    return 0;
}
