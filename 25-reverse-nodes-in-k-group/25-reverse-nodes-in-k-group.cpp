/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1)
            return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        int c=0;
        ListNode *curr=dummy,*prev=dummy,*nex=dummy;
        while(curr->next!=NULL)
        {
            c++;
            curr=curr->next;
        }
        while(c>=k)
        {
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++)
            {
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            c-=k;
            prev=curr;
        }
        return dummy->next;
    }
};