class Solution {
public:
    void postorder(TreeNode* root, vector<int>& v) 
    {
        if (root == nullptr)
            return;
        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>post;
        postorder(root, post);
        return post;
    }
};