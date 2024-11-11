class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
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
