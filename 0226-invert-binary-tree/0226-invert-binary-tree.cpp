class Solution {
public:
    void mirrorTree(TreeNode *root)  
    {
        if(root==NULL)
            return;
        TreeNode * temp1 = root->left;
        TreeNode * temp2 = root->right;
        root -> left = temp2;
        root->right = temp1;
        mirrorTree(root->left);
        mirrorTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        mirrorTree(root);
        return root;
    }
};