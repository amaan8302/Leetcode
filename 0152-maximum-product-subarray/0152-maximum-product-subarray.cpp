class Solution {
public:
    int solve(vector<int>& nums, int i, int maxProd, int minProd, int& result) {
        int n = nums.size();
        if (i >= n)
            return result;
        
        int tempMax = max({nums[i], maxProd * nums[i], minProd * nums[i]});
        int tempMin = min({nums[i], maxProd * nums[i], minProd * nums[i]});
        
        result = max(result, tempMax);
        
        return solve(nums, i + 1, tempMax, tempMin, result);
    }

    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        return solve(nums, 1, nums[0], nums[0], result);
    }
};
