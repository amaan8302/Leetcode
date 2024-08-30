class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        // int len=0;
        // ListNode* temp = head;
        // while(temp->next!=NULL)
        // {
        //     temp = temp->next;
        //     len++;
        // }
        // if(len>=k)
        //     len = len%k;
        // temp->next=head;
        // ListNode* dummy=temp->next;
        // while(len!=0)
        // {
        //     head = head->next;
        //     len--;
        // }
        // return head->next;
        if(head==NULL || head->next==NULL || k==0)
            return head;
        ListNode* temp = head;
        int len = 1;
        while(temp->next)
        {
            temp = temp->next;
            len++;
        }
        temp ->next = head;
        k=k%len;
        k = len - k;
        while(k!=0)
        {
            temp = temp->next;
            k--;
        }
        head = temp -> next;
        temp -> next = NULL;
        return head;
    }
};