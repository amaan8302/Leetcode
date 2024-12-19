class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void backtrack(vector<vector<int>>& grid, int cnt, int i, int j, int nonObs, int& res) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1)
            return;
        if (grid[i][j] == 2) {
            if (cnt == nonObs) 
                res++;
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        
        for (vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            backtrack(grid, cnt + 1, new_i, new_j, nonObs, res);
        }
        

        grid[i][j] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_i = -1, start_j = -1, nonObs = 0, res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
                if (grid[i][j] != -1) 
                    nonObs++;
            }
        }
        backtrack(grid, 1, start_i, start_j, nonObs, res);
        return res;
    }
};
