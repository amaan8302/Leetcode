class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int maxLen = 1, currLen = 1;
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] > nums[i - 1])
                currLen++;
            else 
            {
                maxLen = max(maxLen, currLen);
                currLen = 1;
            }
        }
        return max(maxLen, currLen);
    }
};