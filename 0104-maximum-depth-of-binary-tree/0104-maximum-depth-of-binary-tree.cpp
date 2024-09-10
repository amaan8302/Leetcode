class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int right = maxDepth(root->right);
        int left= maxDepth(root->left);
        return max(left,right)+1;
    }
};