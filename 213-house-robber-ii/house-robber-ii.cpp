class Solution {
public:
// int robber(int i, vector<int>&nums,int end,vector<int>&dp){
//     if(i>end){
//         return 0;
//     }
//     // if(dp[i]!=-1){
//     //     return dp[i];
//     // }
//     return dp[i]=max(nums[i] + robber(i + 2, nums, end, dp),
//             robber(i + 1, nums, end, dp));
// }

    int robber(int start, vector<int>& nums, int end) {
        vector<int> dp(nums.size() + 2, 0);
        for (int i = end; i >= start; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[start];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,-1);
         vector<int> dp2(n, -1);
        
        if(n==1){
            return nums[0];
        }
        int rob1=robber(0,nums,n-2);
        int rob2=robber(1,nums,n-1);
        return max(rob1,rob2);
    }
};