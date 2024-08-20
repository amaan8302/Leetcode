class Solution {
public:
    // int solveTab(vector<int>& nums1, vector<int>& nums2)
    // {
    //     int n = nums1.size();
    //     vector<vector<int>>dp(n+1,vector<int>(2,0));
    //     for(int index = n-1 ; index>=1;index--)
    //     {
    //         for(int swapped=1;swapped>=0;swapped--)
    //         {
    //             int ans=INT_MAX;
    //             int prev1 = nums1[index-1];
    //             int prev2 = nums2[index-1];
    //             // Importantttt
    //             if(swapped)
    //                 swap(prev1,prev2);
    //             // No swap case
    //             if(nums1[index]>prev1&&nums2[index]>prev2)
    //                 ans = dp[index+1][0];
    //             // swap wala case
    //             if(nums1[index] > prev2 && nums2[index]>prev1)
    //                 ans = min(ans,1 + dp[index+1][1]);
    //             dp[index][swapped]=ans;
    //         }
    //     }
    //     return dp[1][0];
    // }
    int solveTab2(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index = n-1 ; index>=1;index--)
        {
            for(int swapped=1;swapped>=0;swapped--)
            {
                int ans=INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];
                // Importantttt
                if(swapped)
                    swap(prev1,prev2);
                // No swap case
                if(nums1[index]>prev1&&nums2[index]>prev2)
                    ans = next[0];
                // swap wala case
                if(nums1[index] > prev2 && nums2[index]>prev1)
                    ans = min(ans,1 + next[1]);
                curr[swapped]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) 
    {   
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1)); //swap me ya to 0 ya to 1 ayegi, only 2 values
        // bool swapped=0;//previous indexes were swapped or not
        return solveTab2(nums1,nums2); //0 index pe -1 he, ishiliye index = 1 se start kia he
    }
};