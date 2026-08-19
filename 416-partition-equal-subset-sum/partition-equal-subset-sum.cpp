class Solution {
public:
bool solve(int i,vector<int>& nums,int target,vector<vector<int>>&dp){
    if(i==nums.size()){
        return false;
    } 
    if(target==0){
        return true;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool pick=false;
    if(nums[i]<=target){
     pick=solve(i+1,nums,target-nums[i],dp);}
    
        bool notpick=solve(i+1,nums,target,dp);
    

    return dp[i][target]=pick || notpick;

}
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int j=0;j<nums.size();j++){
            sum += nums[j];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(0,nums,target,dp);
    }
};