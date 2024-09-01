class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0; 
        ListNode *temp1 = headA, *temp2 = headB;

        while (temp1 != NULL) 
        {
            n1++;
            temp1 = temp1->next;
        }

        while (temp2 != NULL) 
        {
            n2++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;

        if (n1 > n2)
        {
            int diff = n1 - n2;
            while (diff--) 
                temp1 = temp1->next;
        } 
        else if (n2 > n1) 
        {
            int diff = n2 - n1;
            while (diff--) 
                temp2 = temp2->next;
        }

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};
