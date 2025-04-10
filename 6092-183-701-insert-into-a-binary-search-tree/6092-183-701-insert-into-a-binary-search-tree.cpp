class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int tar) {
        if(!root)
            return new TreeNode(tar);
        if(root->val < tar)
            root->right = insertIntoBST(root->right,tar);
        else if(root->val > tar)
            root->left = insertIntoBST(root->left,tar);
        return root;
    }
};