class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;
        
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        if (totalSum == 0) return 0;
        
        int target = totalSum;
        unordered_map<int, int> mod_map;
        mod_map[0] = -1;
        
        int prefixSum = 0;
        int minLength = n;
        
        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            int requiredMod = (prefixSum - target + p) % p;
            
            if (mod_map.count(requiredMod)) {
                minLength = min(minLength, i - mod_map[requiredMod]);
            }
            
            mod_map[prefixSum] = i;
        }

        if (minLength == n) {
            return -1;
        }
        
        return minLength;
    }
};
