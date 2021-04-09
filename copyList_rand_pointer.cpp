/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *itr=head,*next;
        while(itr!=NULL)
        {
            next=itr->next;
            Node *copy=new Node(itr->val);
            itr->next=copy;
            copy->next=next;
            itr=next;
        }
        itr=head;
        while(itr!=NULL)
        {
            if(itr->random!=NULL)
            {
                itr->next->random=itr->random->next;
            }
            itr=itr->next->next;
        }
        Node *dummy=new Node(0);
        itr=head;
        Node *n,*copy=dummy;
        while(itr!=NULL)
        {
            next=itr->next->next;
            n=itr->next;
            copy->next=n;
            copy=n;
            itr->next=next;
            itr=next;
        }
        return dummy->next;
    }
};
