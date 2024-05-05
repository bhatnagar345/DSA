#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    int data;
    Node *next;
}*root = NULL;

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

//make loop
void makeloop(Node *p,int pos)
{
    Node * start = p;
    Node * temp = p;
    int coun = 1;
    while(temp->next != NULL)
    {
        if(coun == pos)
        {
            start = temp;
        }
        temp = temp->next;
        coun++;
    }
    temp->next = start;
}

//function for detecting the loop
void detectloop(Node *p)
{
   Node *fast = p;
    Node * slow = p;
    do{
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
        {
            cout<<endl<<endl<<"there is loop "<<endl;
            return;
        }
    }while(fast->next != NULL);
    cout<<endl<<endl<<"there is NOOOOOOO loop "<<endl;
}


//detect loop
void removloop(Node *p)
{
    Node *fast = p;
    Node * slow = p;
    do{
        fast = fast->next->next;
        slow = slow->next;
    }while(fast != slow);
        fast = p;
    while(fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

void removeloopwithmap(Node *p)
{
    unordered_map<Node*,int>m;
    Node * last = p;
    while(p != NULL)
    {
        if(m.find(p) == m.end())
        {
            m[p]++;
            last = p;
            p = p->next;
        }
        else{
            last->next = NULL;
            break;
        }
    }
}




//function for displaying the linked list
void display(Node *p)
{
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    root = new Node;
    int a[]= {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(int);
    create(root,a,n);
    display(root);
    makeloop(root , 2);

    detectloop(root);
    removloop(root);
    cout<<endl<<endl<<"after removing the loop : ";
    display(root);
    return 0;
}
