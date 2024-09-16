class Solution {
public:
    TreeNode* inorderToBST(std::vector<int>& arr, int start, int end) 
    {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = inorderToBST(arr, start, mid - 1);
        root->right = inorderToBST(arr, mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return NULL;
        return inorderToBST(nums,0,n-1);
    }
};