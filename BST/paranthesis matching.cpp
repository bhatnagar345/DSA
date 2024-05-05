#include<bits/stdc++.h>
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
int isempty()
{
    return top ==NULL;
}

bool isbalanced(string x)
{
    int i=0;
    while(i < x.length())
    {
        if(x.at(i)== '(' ||x.at(i)== '[' ||x.at(i)== '{' )
            {
                push(x.at(i));
            }
         else if(x.at(i)== ')' ||x.at(i)== ']' ||x.at(i)== '}' )
         {
             if(isempty())
             {
                 return false;
             }
             pop();
         }
         i++;
    }
    if(isempty())
         {
             return true;
         }
         return false;
}

int main()
{

    string x ="[({[([{}])]})}";
    if(isbalanced(x))
    {
        cout<<endl<<"it is paranthesis matching "<<endl;
    }
    else{

        cout<<endl<<"it is not paranthesis matching "<<endl;
    }

    return 0;
}
