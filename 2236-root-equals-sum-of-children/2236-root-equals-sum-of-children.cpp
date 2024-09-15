class Solution {
public:
    void sum(TreeNode* root,int &s)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            s = s + root->val;
        sum(root->left,s);
        sum(root->right,s);
    }
    bool checkTree(TreeNode* root) 
    {
        int n = root->val;
        int s = 0;
        sum(root,s);
        return (s==n);
    }
};