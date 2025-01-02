class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col = matrix[0].size();
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 1 ; j < col ; j++)
                matrix[i][j] += matrix[i][j-1];
        }
        int res = 0;
        for(int i = 0 ; i < col ; i++)
        {
            for(int j = i ; j < col ; j++)
            {
                unordered_map<int,int>mp;
                mp.insert({0,1});
                int sum = 0;
                for(int k = 0 ; k<rows;k++)
                {
                    sum+=matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);
                    if(mp.find(sum-target)!=mp.end())
                        res+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return res;
    }
};