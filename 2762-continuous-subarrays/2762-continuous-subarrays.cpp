class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int i = 0, j = 0;
        int high = nums[0], low = nums[0];
        map<int,int>mp;
        while (j < nums.size())
        {
            // high = max(nums[j], high);
            // low = min(nums[j], low);
            mp[nums[j]]++;
            while(abs(mp.rbegin()->first - mp.begin()->first)>2)
            {
                mp[nums[i]] -=1;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            // if (abs(high - low) <= 2) {
            //     res += (j - i + 1);
            //     j++;
            // } else 
            // {
            //     if (nums[i] == high || nums[i] == low) 
            //     {
            //         high = *max_element(nums.begin() + i + 1, nums.begin() + j + 1);
            //         low = *min_element(nums.begin() + i + 1, nums.begin() + j + 1);
            //     }
            //     i++;
            // }
            res += j-i+1;
            j++;
        }
        return res;
    }
};
