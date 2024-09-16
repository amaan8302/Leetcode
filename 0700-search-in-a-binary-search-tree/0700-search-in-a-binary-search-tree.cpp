class Solution {
public:
    TreeNode* bst(TreeNode* root, int val) {   
        while (root != NULL) {
            if (root->val == val)
                return root;
            if (root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return NULL;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return bst(root, val);
    }
};