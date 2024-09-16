class Solution {
public:
    TreeNode* solve(vector<int>&pre, int mini , int maxi , int &i)
    {
        int n = pre.size();
        if(i>=n)
            return NULL;
        if(pre[i]<mini || pre[i]>maxi)
            return NULL;
        TreeNode* temp = new TreeNode(pre[i++]);
        temp->left = solve(pre,mini,temp->val,i);
        temp->right = solve(pre,temp->val,maxi,i);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        return solve(preorder,mini,maxi,i);  
    }
};