class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) 
            return 0;
        std::sort(nums.begin(), nums.end());
        int prev = nums[0];
        int curr = nums[0];
        int cnt = 1;
        int longest = 1;
        for (int i = 1; i < nums.size(); i++) {
            curr = nums[i];
            if (curr == prev) 
                continue;
            if (curr != prev + 1)
                cnt = 1;
            else
                cnt++;
            longest = max(longest, cnt);
            prev = curr;
        }
        return longest;
    }
};