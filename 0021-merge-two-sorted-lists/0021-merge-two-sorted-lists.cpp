class Solution {
public:
    ListNode *findMid(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while (left != NULL && right != NULL)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        ans = ans->next;
        return ans;
    }
    ListNode *mergeSort(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        ListNode* temp = list1;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next=list2;
        return mergeSort(list1);
    }
};