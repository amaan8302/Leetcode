class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
    int left = 0, right = 0, usedBits = 0, maxLength = 0;
    
    while (right < nums.size()) {
        while ((usedBits & nums[right]) != 0) {
            usedBits ^= nums[left]; 
            left++;
        }
        
        usedBits |= nums[right];
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    
    return maxLength;
}

};