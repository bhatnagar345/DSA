    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int s1 =0,rev1 =0;
        int s2 =0,rev2 =0;
        while(first)
        {
            s1 = s1*10 + first->data;
            first = first->next;
        }
        while(s1>0)
        {
            rev1 = rev1*10 + s1%10;
            s1 = s1/10;
        }
        while(second)
        {
            s2 = s2*10 + second->data;
            second = second->next;
        }
        while(s2>0)
        {
            rev2 = rev2*10 + s2%10;
            s2 = s2/10;
        }
        int an = s1 + s2;
        int rev3 = an;
         struct Node * ans = new Node(rev3%10);
         rev3 = rev3/10;
         struct Node * last = ans;
         while(rev3>0)
         {
             struct Node *t = new Node(rev3%10);
             last->next = t;
             last = t;
             rev3 = rev/10;
         }
         return ans;
    }
