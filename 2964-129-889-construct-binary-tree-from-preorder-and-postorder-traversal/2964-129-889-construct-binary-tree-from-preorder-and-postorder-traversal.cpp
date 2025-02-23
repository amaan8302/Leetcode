class Solution {
public:
    unordered_map<int, int> postIndexMap;
    int preIndex = 0;

    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (left == right) return root;
        int postIndex = postIndexMap[preorder[preIndex]];
        root->left = construct(preorder, postorder, left, postIndex);
        root->right = construct(preorder, postorder, postIndex + 1, right - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        for (int i = 0; i < n; i++) postIndexMap[postorder[i]] = i;
        return construct(preorder, postorder, 0, n - 1);
    }
};