class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        if(a==NULL || b==NULL)
            return NULL;
        ListNode * temp1 = a;
        ListNode * temp2 = b;
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2)
                return temp1;
            if(temp1==NULL)
                temp1=b;
            if(temp2==NULL)
                temp2=a;
        }
        return temp1;
    }
};