class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int i=0, j=0;
        int n = nums.size();
        long long currSum = 0;
        long long ans = 0;
        unordered_set<int>m;
        while(j<n)
        {
            while(m.count(nums[j]))
            {
                currSum -=nums[i];
                m.erase(nums[i]);
                i++;
            }
            currSum += nums[j];
            m.insert(nums[j]);
            if(j-i+1==k)
            {
                ans = max(ans,currSum);
                currSum-=nums[i];
                m.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};