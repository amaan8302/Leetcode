class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size = 0;
        for(int i : nums)
        {
            if(i==1)
                size++;
        }
        int maxi = INT_MIN;
        int i = 0, j = 0;
        int n = nums.size();
        // vector<int>res(2*n);
        // for(int i = 0 ; i < 2*n ; i++)
        //     res[i] = nums[(n+i)%n];
        int CurrOnes = 0;
        while(j<2*n)
        {
            if(j - i + 1<=size)
            {
                if(nums[j%n]==1)
                    CurrOnes++;
                j++;
            }
            else
            {
                maxi = max(maxi , CurrOnes);
                if(nums[i%n]==1)
                    CurrOnes--;
                i++;
            }
        }
        return size - maxi;
    }
};