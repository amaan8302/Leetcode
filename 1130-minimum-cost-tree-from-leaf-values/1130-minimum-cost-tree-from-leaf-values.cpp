class Solution {
public:     
    int solvetab(vector<int>& arr, map<pair<int,int>,int>& maxi)
    {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int left = n-1; left >= 0; left--)
        {
            for(int right = left + 1; right < n; right++)
            {
                int ans = INT_MAX;
                for(int i = left; i < right; i++)
                {
                    ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) 
    {
        map<pair<int,int>,int> maxi;
        for(int i = 0; i < arr.size(); i++)
        {
            maxi[{i,i}] = arr[i];
            for(int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);    
            }
        }
        return solvetab(arr, maxi);
    }
};