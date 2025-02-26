class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }
        
        int minSum = nums[0];
        int currentMinSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentMinSum = std::min(nums[i], currentMinSum + nums[i]);
            minSum = std::min(minSum, currentMinSum);
        }
        return max(abs(maxSum),abs(minSum));
    }
};