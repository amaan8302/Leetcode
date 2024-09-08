class Solution {
public:
    int sum(vector<int>& ans) {
        int s = 0;
        for (int i : ans)
            s = i + 10 * s;
        return s;
    }
    void solve(TreeNode* root, vector<int>& ans, int& s) {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
            s = s + sum(ans);
        else 
        {
            solve(root->left, ans, s);
            solve(root->right, ans, s);
        }
        ans.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        int s = 0;
        solve(root, ans, s);
        return s;
    }
};