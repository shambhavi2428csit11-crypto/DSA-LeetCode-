class Solution {
public:
int solve(int i,vector<int>& nums, int target,vector<vector<int>>&dp){
    if(i==nums.size()){
        if(target==0){
            return 1;
        }
        else {
            return 0;
        }
    }int index = target + 2002;
    if(dp[i][index]!=-1){
        return dp[i][index];
    }
    int plus=solve(i+1,nums,target+nums[i],dp);
    int minus=solve(i+1,nums,target-nums[i],dp);
    return dp[i][index]=plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(4000, -1));
        return solve(0,nums,target,dp);
    }
};