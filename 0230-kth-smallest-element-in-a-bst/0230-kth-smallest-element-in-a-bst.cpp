class Solution {
public:
    void inorder(TreeNode* root,vector<int>&res)
    {   
        if(root==NULL)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        inorder(root,res);
        if(k<1 || k > res.size())
            return -1;
        return res[k-1];
    }
};