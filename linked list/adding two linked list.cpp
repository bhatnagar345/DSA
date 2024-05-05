/*
Given two numbers represented by two lists, write a function that returns the sum list.
The sum list is a list representation of the addition of two input numbers.

Example:

Input:
List1: 5->6->3 // represents number 365
List2: 8->4->2 // represents number 248
Output:
Resultant list: 3->1->6 // represents number 613
Explanation: 365 + 248 = 613
Input:
List1: 7->5->9->4->6 // represents number 64957
List2: 8->4 // represents number 48
Output:
Resultant list: 5->0->0->5->6 // represents number 65005
Explanation: 64957 + 48 = 65005
*/



#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
}*root1 = NULL;

//creating linked list using array
void create(Node *p,int a[], int n)
{
    Node * last;
    int x;
    //p = new Node;
    p = new Node(a[0]);
    last = p;
    for(int i=1; i<n; i++)
    {
        Node *r = new Node(a[i]);
        last->next = r;
        last = r;
    }
}

Node*reverse(Node*root)
    {
        Node*temp=root;
        Node*prev=NULL;
        Node*cur=root;
        while(cur)
        {
            Node*nexti=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nexti;
        }
        return prev;
    }
    Node* addTwoLists(Node* first, Node* second)
    {
        // code here
        Node*a =reverse(first);
        Node*b=reverse(second);
        Node*ans=new Node(((a->data)+(b->data))%10);
        Node*ans1=ans;
        int carry=(a->data+b->data)/10;
        a=a->next;
        b=b->next;
        
        int one=0,two=0,sum=0;
        while(a||b)
        {
            if(a)
            {
               one=a->data;
               a=a->next;
            }
            else one=0;
            if(b)
            {
                two=b->data;
                b=b->next;
            }
            else two=0;
            sum=one+two+carry;
            int w=sum%10;
            carry=sum/10;
            Node*temp=new Node(w);
            ans1->next=temp;
            ans1=ans1->next;
        }
        if(carry)
        {
           Node*temp=new Node(1);
            ans1->next=temp;
            ans1=ans1->next; 
        }
        ans=reverse(ans);
        return ans;
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
    root1 = NULL;
    Node *root2 = NULL;
    int a[] = {5,6,3};
    int n = sizeof(a)/sizeof(int);
    int b[] = {8,4,2};
    int n2 = sizeof(b)/sizeof(int);
    create(root1,a,n);
    create(root2,b,n2);
    cout<<endl<<endl<<"the first list is : ";
    display(root1);
    cout<<endl<<endl<<"the second list is : ";
    display(root2);

    Node * third = addTwoLists(root1,root2);
    cout<<endl<<endl<<"After adding the two linked lists in third linked list : ";
    display(third);

    return 0;
}



