class Solution {
public:
    int kadaneMin(vector<int> &nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentSum = std::min(nums[i], currentSum + nums[i]);
            maxSum = std::min(maxSum, currentSum);
        }
        return maxSum;
    }
    int kadaneMax(vector<int> &nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> res(2 * nums.size());
        for (int i = 0; i < 2 * nums.size(); i++)
            res[i] = nums[i % nums.size()];
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
            sum+=nums[i];
        int minSum = kadaneMin(nums), maxSum = kadaneMax(nums), circular = sum - minSum;
        if(maxSum>0)
            return max(maxSum,circular);
        return maxSum;
    }
};