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
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        int i = 0;
        int j = v.size()-1;
        while(i<j)
        {   
            int sum = v[i]+v[j];
            if(sum==k)
                return true;
            if(sum<k)
                i++;
            if(sum>k)
                j--;
        }
        return false;
    }
};