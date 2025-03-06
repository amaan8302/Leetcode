class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    long long sum_actual = 0, sum_square_actual = 0;
    long long sum_expected = (1LL * n * n * (n * n + 1)) / 2;
    long long sum_square_expected = (1LL * n * n * (n * n + 1) * (2 * n * n + 1)) / 6;

    int repeated, missing;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            sum_actual += num;
            sum_square_actual += 1LL * num * num;
        }
    }
    
    long long diff = sum_actual - sum_expected; // a - b
    long long square_diff = sum_square_actual - sum_square_expected; // a^2 - b^2
    
    long long sum = square_diff / diff; // (a^2 - b^2) / (a - b) = a + b
    
    repeated = (diff + sum) / 2;
    missing = (sum - diff) / 2;
    
    return {repeated, missing};
}

};