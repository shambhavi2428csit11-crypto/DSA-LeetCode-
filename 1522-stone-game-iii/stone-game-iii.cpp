class Solution {
public:
    int solve(int  i,vector<int>&stoneValue,vector<int>&dp){
        int n=stoneValue.size();
        
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take1=INT_MIN;
        take1=stoneValue[i]-solve(i+1,stoneValue,dp);

        int take2=INT_MIN;
        if(i+1<n){
        take2=(stoneValue[i]+stoneValue[i+1])-solve(i+2,stoneValue,dp);}

        int take3=INT_MIN;
        if(i+2<n){
        take3=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(i+3,stoneValue,dp);}

        return  dp[i]=max(take1,max(take2,take3));
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,-1);
        int ans=solve(0,stoneValue,dp);
        if(ans>0){
            return "Alice";
        }
        else if(ans<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
        
    }
};