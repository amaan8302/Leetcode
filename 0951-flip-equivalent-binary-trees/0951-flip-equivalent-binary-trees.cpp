class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        
        if(root1==NULL && root2 != NULL)
            return 0;
        if(root1!=NULL && root2 == NULL)
            return 0;
        if(root1==NULL && root2 == NULL)
            return 1;
        if(root1->val == root2->val)
        {
            bool flip = flipEquiv(root1->left,root2->right)&&flipEquiv(root1->right,root2->left);
            bool noflip = flipEquiv(root1->right,root2->right)&&flipEquiv(root1->left,root2->left);
            return flip||noflip;
        }
        return 0;
            
    }
};