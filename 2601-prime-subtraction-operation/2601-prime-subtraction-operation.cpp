class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1) return false;
        if (n ==2) return true;
        if(n == 3) return true;
        int ans = n;
        for(int i = 2 ; i < n ; i++)
        {
            if(ans%i==0)
                return 0;
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n-1 ; i++)
        {
            int res = nums[i] - 1;
            while(res > 0 && (!isPrime(res) || (i>0 && nums[i] - res <= nums[i-1])))
                res--;
            nums[i] = nums[i] - res;
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
};
