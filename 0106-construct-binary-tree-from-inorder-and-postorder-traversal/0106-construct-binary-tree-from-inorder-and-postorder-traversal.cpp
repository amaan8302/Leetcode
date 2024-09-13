class Solution {
private:
    int findPosition(vector<int>& inorder, int element)
    {
        for(int i = 0;i<inorder.size();i++)
        {
            if(inorder[i]==element)
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index,int start,int end,int n)
    {
        if(index < 0 || start > end)
            return NULL;
        int element = postorder[index--];//pre order se element nikalke ++ kardo
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder,element); //uss element ki position inorder me
        root->right = solve(inorder,postorder,index,position+1,end/*inorder ka End*/,n);
        root->left = solve(inorder,postorder,index,start/*inorder ka start*/,position-1,n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index=n-1;
        return solve(inorder,postorder,index,0,n-1,n);
    }
};