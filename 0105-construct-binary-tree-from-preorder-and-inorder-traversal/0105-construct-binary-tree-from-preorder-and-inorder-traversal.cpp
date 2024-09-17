class Solution {
public:
    int findPosition(vector<int>& inorder, int element)
    {
        for(int i = 0;i<inorder.size();i++)
        {
            if(inorder[i]==element)
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index,int start,int end,int n)
    {
        if(index>=n || start>end)
            return NULL;
        int element = preorder[index++];//pre order se element nikalke ++ kardo
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder,element); //uss element ki position inorder me
        root->left = solve(preorder,inorder,index,start/*inorder ka start*/,position-1,n);
        root->right = solve(preorder,inorder,index,position+1,end/*inorder ka End*/,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = inorder.size();
        TreeNode* ans = solve(preorder,inorder,preOrderIndex,0,n-1,n);
        return ans;
    }
};