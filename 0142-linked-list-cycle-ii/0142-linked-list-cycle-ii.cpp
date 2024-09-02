class Solution {
public:
    ListNode *InsertionPoint(ListNode *head)
    {
        if(head==NULL||head->next==NULL)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;
            slow = slow->next;
            if(fast==slow)
                return fast;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return nullptr;
        ListNode * intersection = InsertionPoint(head);
        if(intersection==NULL)
            return nullptr;
        ListNode * slow = head;
        while(slow!=intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
};