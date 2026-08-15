class Solution {
public:
    // int money(int i,vector<int>&nums,int n,vector<int>&dp){
       
    //    if(i>=n){
    //         return 0;
    //     }
    //      if(dp[i]!=-1){
    //         return dp[i];
    //     }
        
    //     return dp[i]= max( nums[i] + money(i + 2, nums,n,dp), money(i + 1, nums,n,dp) );
       
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int>dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n-1];
    }
};