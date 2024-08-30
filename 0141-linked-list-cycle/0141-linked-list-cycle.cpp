/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==0)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow!= NULL && fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)   
                fast = fast->next;
            slow = slow -> next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};