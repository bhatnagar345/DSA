#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node * right;
};
class Queue
{
private:
    int first;
    int rear;
    Node **q;
    int Size;
public:
    Queue()
    {
        Size = 10;
        first = rear =-1;
        q = new Node*[Size];
    }
    Queue(int n)
    {
        Size = n;
        first = rear =-1;
        q = new Node*[Size];
    }
    bool isempty();
    void enqueue(Node *x);
    Node * dequeue();
};
bool Queue ::isempty()
{
    if(first == rear)
    {
        return 1;
    }
    return 0;
}

void Queue::enqueue(Node *x)
{
    if(rear == Size)
    {
        cout<<"Queue is Full"<<endl;
        return ;
    }
    rear++;
    q[rear] = x;
}
Node * Queue ::dequeue()
{
    Node *e;
    if(isempty())
    {
        cout<<"Queue is empty "<<endl;
        return NULL;
    }
    first++;
    e = q[first];
    return e;
}

class tree
{
private:
    Node *root;
public:
    tree()
    {
        root = NULL;

    }
    void creating();
    void postorder(Node *p);
    void postorder()
    {
        postorder(root);
    }
    vector<int> levelorder(Node *p);
    vector<int> levelorder()
    {
        levelorder(root);
    }
};




void tree::creating()
{
    Node *p,*t;
    int x;
    Queue q(100);
    cout<<"Write down the root value : ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->left = root->right = NULL;
    q.enqueue(root);
    while(! q.isempty())
    {
        p = q.dequeue();
        cout<<endl<<endl<<"Write down the "<<p->data<<" left child : ";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->left =t;
            q.enqueue(t);
        }
        cout<<endl<<endl<<"Write down the "<<p->data<<" rigth child : ";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->right =t;
            q.enqueue(t);
        }
    }
}



vector<int> tree::levelorder(Node *p)
{
    vector<int>vec{};
    Node *t;
    queue<Node*>q;
    q.push(p);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(t->left)
        {
            vec.push_back(t->left->data);
            q.push(t->left);
        }
        if(t->right)
        {
            vec.push_back(t->right->data);
            q.push(t->right);
        }
    }
    return vec;
}



int main()
{
    tree bt;
    bt.creating();

    vector<int>vec1 =  bt.levelorder();
    cout<<endl<<endl<<"the levelorder traversal of binary tree  : ";

      for(auto elm : vec1)
      {
          cout<<elm<<"->";
      }

    cout<<"NULL"<<endl;
    return 0;
}

