class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root==NULL)
            return;
        while(root!=NULL)
        {
            if(root->left)
            {
                TreeNode* temp = root->left;
                while(temp->right)
                    temp = temp ->right;
                temp -> right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};