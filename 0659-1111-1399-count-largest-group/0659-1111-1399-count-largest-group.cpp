class Solution {
public: 
    int SumDigit(int n)
    {
        int sum = 0;
        while(n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int maxSize = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            mini = min(mini, SumDigit(i));
            maxi = max(maxi , SumDigit(i));
            mp[SumDigit(i)]++;
            maxSize = max(maxSize,mp[SumDigit(i)]);
        }
        int cnt = 0;
        for(int i = mini ; i <= maxi ; i++)
        {
            if(mp[i]==maxSize)
                cnt++;
        }
        return cnt;
    }
};