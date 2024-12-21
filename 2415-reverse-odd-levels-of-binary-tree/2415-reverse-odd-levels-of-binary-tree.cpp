class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while(!q.empty()) {
            int n = q.size();
            vector<TreeNode*> nodes;
            
            for(int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left) {
                    q.push(curr->left);
                    nodes.push_back(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                    nodes.push_back(curr->right);
                }
            }
            
            if(level % 2 == 0 && !nodes.empty()) {
                int i = 0, j = nodes.size() - 1;
                while(i < j) {
                    swap(nodes[i]->val, nodes[j]->val);
                    i++;
                    j--;
                }
            }
            
            level++;
        }
        
        return root;
    }
};