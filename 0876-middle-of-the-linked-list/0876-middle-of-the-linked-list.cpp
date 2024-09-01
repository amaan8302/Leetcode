class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL)
        {
            fast = fast->next;
            if(fast->next!=NULL)
                fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};