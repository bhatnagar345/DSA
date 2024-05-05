/*Given a root of a tree, and an integer k. Print all the nodes which are at k distance from root.
For example, in the below tree, 4, 5 & 8 are at distance 2 from root.
             1
            / \
           2   3
          / \  /
         4  5  8
*/


#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node * left;
    Node * right;
};

Node * Rinserting(Node **q,int key)
{
    Node *p = *q;
    Node *t = NULL;
    if(p == NULL)
    {
        t= new Node;
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }
    if(p->data < key)
    {
        p->left = Rinserting(&p->left,key);
    }
    if(p->data > key)
    {
        p->right = Rinserting(&p->right,key);
    }
    return p;
}


void inorder(Node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<"->";
        inorder(p->right);
    }
}

 unordered_map<Node*,Node*>parent;
    void dfs(Node* curr, Node * par)
    {
        if(!curr)return;
        parent[curr] = par;
        dfs(curr->left,curr);
        dfs(curr->right,curr);
    }
    vector<int> distanceK(Node* root, Node* target, int k) {
        dfs(root,NULL);
        queue<Node*>q;
        q.push(target);
        unordered_set<Node*>visited;
        while(!q.empty() and k)
        {
            k = k-1;
            int n = q.size();
            for(int i =0;i<n;i++)
            {
                Node* temp = q.front();
                q.pop();
                visited.insert(temp);
                if(!visited.count(temp->left) and temp->left)
                { 
                    q.push(temp->left);
                   cout<<temp->left->data<<" ";
                }
                if(!visited.count(temp->right) and temp->right)
                {
                     q.push(temp->right);
                     cout<<temp->right->data;
                }
                if(!visited.count(parent[temp]) and parent[temp]) 
                {
                    q.push(parent[temp]);
                    cout<<" "<<parent[temp]->data<<endl;
                }
            }
        }
        vector<int>ans;
        cout<<q.size()<<endl;
        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }



int main()
{
    Node * root = NULL;
    int a[] = {3,5,21,7,6,24,45,8,34,48,50,66,77,88,90};
    int n = sizeof(a)/sizeof(int);
    int i=0;
    root = Rinserting(&root,a[i]);
    for( i=1; i<n; i++)
    {
        Rinserting(&root,a[i]);
    }


    inorder(root);
    cout<<"NULL"<<endl;

    vector<int>vec3 = distanceK(root,root->left,2);
    for(auto elm : vec3)
    {
        cout<<elm<<" ";
    }
    return 0;
}
