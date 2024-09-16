// class Solution {
// public:
//     bool solve(TreeNode* root, int mini , int maxi)
//     {
//         if(root==NULL)
//             return 1;
//         if(root->val>mini && root->val<maxi)
//         {
//             bool left = solve(root->left,mini,root->val);
//             bool right = solve(root->right,root->val,maxi);
//             return left && right;
//         }
//         return 0;
//     }
//     bool isValidBST(TreeNode* root) {
//         int mini = LONG_MIN;
//         int maxi = LONG_MAX;
//         return solve(root,mini,maxi);
//     }
// };
class Solution {
public:
    bool bst(TreeNode* root, long min, long max)
    {
        if(root==NULL)
            return true;
        if(root->val>min && root->val<max)
        {
            bool left = bst(root->left,min,root->val);
            bool right = bst(root->right,root->val,max);
            return left&& right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return bst(root,LONG_MIN, LONG_MAX);
    }   
};