#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    char data;
    Node *next;
}*root = NULL;

//creating linked list using array
void create(Node *p,string a, int n)
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
//function for palindrome
void ispalindrome(Node **p)
{
    Node *pt = *p;
    stack<char>stk;
    while(pt)
    {
        stk.push(pt->data);
        pt = pt->next;
    }
    pt = *p;
    while(pt)
    {
        char i = stk.top();
        stk.pop();
        if(pt->data != i)
        {
            cout<<"there is not palindrome "<<endl;
            return;
        }
        pt = pt->next;
    }
    cout<<" there is palindrome "<<endl;
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
    string s = "abcdedcba";
    root = new Node;
    int n = s.length();
    create(root,s,n);
    display(root);
    ispalindrome(&root);
    return 0;
}
