class Solution {
public:
    void dfs(vector<vector<int>>& image,int color, int i, int j, int original)
    {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j] != original)
            return;
        image[i][j] = color;
        dfs(image,color, i+1,j,original);
        dfs(image,color, i,j+1,original);
        dfs(image,color, i,j-1,original);
        dfs(image,color, i-1,j,original);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        if (initial != color) {
            dfs(image, color, sr, sc, initial);
        }
        return image;
    }
};