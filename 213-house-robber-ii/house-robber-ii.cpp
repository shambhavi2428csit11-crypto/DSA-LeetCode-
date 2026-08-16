class Solution {
public:
int robber(int i, vector<int>&nums,int end,vector<int>&dp){
    if(i>end){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    return dp[i]=max(nums[i] + robber(i + 2, nums, end, dp),
            robber(i + 1, nums, end, dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,-1);
         vector<int> dp2(n, -1);
        
        if(n==1){
            return nums[0];
        }
        int rob1=robber(0,nums,n-2,dp1);
        int rob2=robber(1,nums,n-1,dp2);
        return max(rob1,rob2);
    }
};