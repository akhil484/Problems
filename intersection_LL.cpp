 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempa=headA;
        ListNode *tempb=headB;
        //time taken to iterate both linkedlist is same and at some point both will become NULL
        while(tempa||tempb)
        {
            if(tempa==tempb)
                return tempa;
            if(tempa)
                tempa=tempa->next;
            else
                tempa=headB;
            if(tempb)
                tempb=tempb->next;
            else
                tempb=headA;
        }
        return NULL;
    }
