class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected) {
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[node][i] == 1 && !visited[i]) {
                dfs(i, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                cnt++;
                dfs(i, visited, isConnected);
            }
        }
        return cnt;
    }
};
