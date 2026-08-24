class Solution {
public:
    int solve(int i,    vector<int>& prefix,int n, vector<int>& dp){
        if(i==n-1){
            return prefix[i];
        }
        if( dp[i]!=-1){
            return dp[i];
        }
        int skip=solve(i+1,prefix,n,dp);
        int take=prefix[i]-skip;
         
        return dp[i]=max(take,skip);
        
    }
    
    int stoneGameVIII(vector<int>& stones) {
        vector<int> prefix(stones.size());
        prefix[0]=stones[0];
        for(int i=1;i<stones.size();i++){
            prefix[i]=stones[i]+prefix[i-1];
        }
        int n=stones.size();
        vector<int> dp(n,-1);
        return solve(1,prefix,n,dp);
    }
};
