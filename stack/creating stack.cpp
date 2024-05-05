#include<iostream>
using namespace std;
class Node
{
public:
    int data ;
    Node *next;
}*top = NULL;

void push(int x)
{
    Node * t= new Node;
    t->data = x;
    t->next = top;
    top = t;
}
int pop()
{
    int x;
    Node * t = top;
    top = top->next;
    delete t;
    return x;
}
void display(Node* p)
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
    int a[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        push(a[i]);
    }
    pop();
    display(top);
    return 0;
}
