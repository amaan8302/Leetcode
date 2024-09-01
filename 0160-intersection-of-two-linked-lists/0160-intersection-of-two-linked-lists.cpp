class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode *,bool>visited;
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        while(temp1!=NULL||temp2!=NULL)
        {
            if(temp1!=NULL)
            {
                if(visited[temp1])
                    return temp1;
                visited[temp1]=1;
                temp1=temp1->next;
            }
            if(temp2!=NULL)
            {
                if(visited[temp2])
                    return temp2;
                visited[temp2]=1;
                temp2=temp2->next;
            }
        }
        return NULL;
    }
};