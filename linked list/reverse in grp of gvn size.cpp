/*Given a linked list, write a function to reverse every k nodes (where k is an input to the function).

Example:

Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL
Input: 1->2->3->4->5->6->7->8->NULL, K = 5
Output: 5->4->3->2->1->8->7->6->NULL
*/
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

// using reverse array in a group
struct node *reverseIt (struct node *head, int k)
    { 
        // Complete this method
        vector<int>v;
        int n =0;
        node * p = head;
        while(p)
        {
            n = p->data;
            p = p->next;
            v.push_back(n);
        }
        int l = v.size();
        for(int i=0;i<v.size();i = i+k)
        {
            int last = min(i+k-1,l-1);
            int start = i;
            while(start < last)
            {
                swap(v[start++],v[last--]);
            }
        }
        Node * ans = new Node(v[0]); 
        p = ans;
        for(int i=1;i<v.size();i++)
        {
            Node *q = new Node(v[i]);
            p->next = q;
            p = q;
        }
        return ans;
    }
};
//function for reverse of given size
void rev(Node ** p,int k)
{
    int a[k] ={0};
    int i=0;
    Node *q =*p;
    while(i<k)
    {
        a[i] = q->data;
        q=q->next;
        i++;
    }
    i--;
    q=*p;
    while(i>=0)
    {
        q->data =a[i];
        q = q->next;
        i--;
    }
}

//reverse function without extra space
Node * Reve(Node *head,int key)
{
    if(!head)
        {
            return NULL;
        }
         Node *q = head;
     Node *p = head;
      Node *r = head;
    p = p->next;
    p=p->next;
    q = q->next;
    r = r->next;
    r->next=head;
    int i=0;
    while(i<key-2)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        i++;
    }
    if(p==NULL)  head->next = NULL;
    else
      head->next = p;
    return q;

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

    int a[] = {1,2,3,4,5,6,5,8,5,5};
    int n = sizeof(a)/sizeof(int);
    create(root1,a,n);
    cout<<endl<<endl<<"display before reversing : ";
    display(root1);
    cout<<endl<<endl<<"display after reversing : ";
     int key = 10;
     Node *u = Reve(root1,key);
    display(u);
     delete root1;
     delete u;
    return 0;
}



