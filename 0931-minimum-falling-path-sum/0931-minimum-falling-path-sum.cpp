class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int row = n - 2; row >= 0; --row) {
        for (int col = 0; col < n; ++col) {
            int down = matrix[row + 1][col];
            int down_left = (col > 0) ? matrix[row + 1][col - 1] : INT_MAX;
            int down_right = (col < n - 1) ? matrix[row + 1][col + 1] : INT_MAX;
            matrix[row][col] += min({down, down_left, down_right});
        }
    }
    return *min_element(matrix[0].begin(), matrix[0].end());
}
};