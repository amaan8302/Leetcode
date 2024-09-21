class Solution {
public:
    void inorder(TreeNode* root, vector<int>&v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        // if(root->left==NULL && root->right==NULL)
        // {
        //     if(root->val==k)
        //         return 1;
        //     else
        //         return 0;
        // }
        vector<int>v;
        inorder(root,v);
        int low = 0;
        int high = v.size()-1;
        while(low<high)
        {
            int sum = v[low]+v[high];
            if(sum==k)
                return 1;
            if(sum>k)
                high--;
            else
                low++;
        }
        return 0;
    }
};