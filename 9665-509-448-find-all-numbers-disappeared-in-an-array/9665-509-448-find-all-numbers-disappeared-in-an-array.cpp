class Solution {
public:
    bool solve(vector<int>& nums , int tar)
    {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]==tar)
                return true;
            else if(nums[mid]>tar)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<int>res;
        int n = nums.size();
        for(int i = 1 ; i<= n ; i++)
        {
            if(solve(nums,i)==false)
                res.push_back(i);
        }
        return res;
    }
};