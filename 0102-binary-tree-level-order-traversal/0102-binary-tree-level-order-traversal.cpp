class Solution {
public:
    void LevelOrder(TreeNode* root,vector<vector<int>>&result) 
    {
        if (root==NULL) return;
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL)
            {
                result.push_back(ans);
                ans.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                ans.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        LevelOrder(root,result);
        return result;
    }
};