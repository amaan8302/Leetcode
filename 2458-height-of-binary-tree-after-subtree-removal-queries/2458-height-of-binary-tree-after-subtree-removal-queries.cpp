class Solution {
public:
    int lvl[100001]; 
    int height[100001];
    int lvlMax[100001];
    int lvl2Max[100001];
    
    int findheight(TreeNode* root, int level) {
        if (root == NULL)
            return 0;
        lvl[root->val] = level;
        int left = findheight(root->left, level + 1);
        int right = findheight(root->right, level + 1);
        height[root->val] = max(left, right) + 1;
        
        if (lvlMax[level] < height[root->val]) {    
            lvl2Max[level] = lvlMax[level];
            lvlMax[level] = height[root->val];
        } else if (lvl2Max[level] < height[root->val]) {
            lvl2Max[level] = height[root->val];
        }
        return height[root->val];
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findheight(root, 0);
        vector<int> result;
        
        for (int &node : queries) {
            int nodeLevel = lvl[node];
            int temp = nodeLevel + (lvlMax[nodeLevel] == height[node] ? lvl2Max[nodeLevel] : lvlMax[nodeLevel]) - 1;
            result.push_back(temp);
        }
        
        return result;
    }
};
