class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int m = mat.size();
        if (m == 0) return result;
        int n = mat[0].size();
        int top = 0, bottom = m-1, left = 0, right = n-1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++)
                result.push_back(mat[top][i]);
            top++;
            if (top > bottom) break;
            for (int i = top; i <= bottom; i++)
                result.push_back(mat[i][right]);
            right--;
            if (left > right) break;
            for (int i = right; i >= left; i--)
                result.push_back(mat[bottom][i]);
            bottom--;
            for (int i = bottom; i >= top; i--)
                result.push_back(mat[i][left]);
            left++;
        }
        return result;
    }
};