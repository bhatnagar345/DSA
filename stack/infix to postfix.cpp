#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data ;
    Node *next;
}*top = NULL;

void push(char x)
{
    Node * t= new Node;
    t->data = x;
    t->next = top;
    top = t;
}
char pop()
{
    char x;
    Node * t = top;
    top = top->next;
    delete t;
    return x;
}
bool isempty()
{
    return top == NULL;
}
int pre(char c)
{
    if(c == '+' ||c == '-')
        return 1;
    else if(c == '*' ||c == '/')
        return 2;

    else
        return 0;
}
int isoperand(char c)
{
    if(c == '+' ||c == '-'||c == '*' ||c == '/')
    {
        return 0;
    }
    else{
        return 1;
    }
}


char *InfiToPost(char *a)
 {
     int i=0,j=0;
     int len = strlen(a);
     char *postfix = new char[len+2];
     while(i<strlen(a))
     {
       if(isoperand(a[i]))
       {
           postfix[j++] = a[i++];
       }
       else{
        if(pre(a[i])> pre(top->data))
        {
            push(a[i]);
            i++;
        }
        else{
            postfix[j++] = pop();
        }
       }
     }
     while(!isempty())
     {
         postfix[j++] = pop();
     }
     postfix[j] = '\0';
     return postfix;
 }

int main()
{
    char *a = "a+b*c-d/e";
    char *ans = InfiToPost(a);
    push('#');
    cout<<ans<<endl;
    return 0;
}

