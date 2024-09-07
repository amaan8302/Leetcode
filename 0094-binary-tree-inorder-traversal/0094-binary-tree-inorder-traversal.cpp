class Solution {
public:
    void inorder(TreeNode* root,vector<int>&insert)
    {
        if(root==NULL)
            return;
        inorder(root->left,insert);
        insert.push_back(root->val);
        inorder(root->right,insert);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>insert;
        inorder(root,insert);
        return insert;
    }
};