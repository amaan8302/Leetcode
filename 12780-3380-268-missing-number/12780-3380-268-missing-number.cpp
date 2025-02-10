class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int>map;
        int n = nums.size();
        for(int i : nums)
            map[i]++;
        for(int i = 0 ; i <= n ; i++)
        {
            if(map[i]==0)
                return i;
        }
        return 0;
    }
};