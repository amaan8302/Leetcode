class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==0 && root->right==0)
            return 1;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        int ans = INT_MIN;
        while(!q.empty())
        {
            int size = q.size();
            unsigned long long mini = q.front().second;
            unsigned long long first,last;
            for(int i = 0 ; i < size ; i++)
            {
                unsigned long long id = q.front().second - mini;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0)
                    first = id;
                if(i==size-1)
                    last = id;
                if(temp->left)
                    q.push({temp->left,id*2+1});
                if(temp->right)
                    q.push({temp->right,id*2+2});
            }
            ans = max(ans, int(last-first+1));
        }
        return ans;
    }
};
