class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
    freq[0] = 1;
    long long count = 0;
    int prefix = 0;

    for (int num : nums) {
        if (num % modulo == k) {
            prefix++;
        }
        int desired = (prefix - k + modulo) % modulo;
        if (freq.count(desired)) {
            count += freq[desired];
        }
        freq[prefix % modulo]++;
    }

    return count;
    }
};