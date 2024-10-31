class Solution {
public:
    long long solve(int robIndex, int facIndex,vector<int>& robot,vector<int>& pos,vector<vector<long long>>&dp )
    {
        if(robIndex>=robot.size())
            return 0;
        if(facIndex >= pos.size())
            return 1e12;
        if(dp[robIndex][facIndex]!=-1)
            return dp[robIndex][facIndex];
        long long take = abs(robot[robIndex]-pos[facIndex])+solve(robIndex+1,facIndex+1,robot,pos,dp);
        long long no = solve(robIndex,facIndex+1,robot,pos,dp);
        return dp[robIndex][facIndex]=min(take,no);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        std::sort(robot.begin(),robot.end());
        std::sort(factory.begin(),factory.end());
        int r = robot.size();
        vector<int>pos;
        for(int i = 0 ; i < factory.size() ; i++)
        {
            int limit = factory[i][1];
            int x = factory[i][0];
            for(int j = 0 ; j < limit ; j++)
                pos.push_back(x);
        }
        int f = pos.size();
        vector<vector<long long>>dp(r+1,vector<long long>(f+1,-1));
        return solve(0,0,robot,pos,dp);
    }
};