class Solution {
public:
    bool isIdentical(TreeNode*p, TreeNode*q)
    {
        if (q == NULL && p == NULL) return true;
        if (q != NULL && p == NULL) return false;
        if (q == NULL && p != NULL) return false;
        bool left = isIdentical(p->left, q->right);
        bool right = isIdentical(p->right, q->left);
        bool value = p->val == q->val;
        return (left && right && value);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        return isIdentical(root->left,root->right);
    }
};