class Solution {
public:
    // int solve(int i,int j,string &s, string &t,vector<vector<int>>&dp){
    //     int n=s.size();
    //     int m=t.size();
    //     // if(j==m)
    //     // {
    //     //     return 1;
    //     // }
    //     // if(i==n)
    //     // {
    //     //     return 0;
    //     // }
    //     // if(dp[i][j]!=-1){
    //     //     return dp[i][j];
    //     // }

    //      if(s[i]==t[j]){
    //      int take=solve(i+1,j+1,s,t,dp);
    //      int nottake=solve(i+1,j,s,t,dp);
    //      return dp[i][j]=take+nottake;
    //     }
    //     return dp[i][j]=solve(i+1,j,s,t,dp);

    // }

    int numDistinct(string s, string t) {
        long long n=s.size();
        long long m=t.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        for(long long i=0;i<=m;i++){
            dp[n][i]=0;
        }
        for(long long i=0;i<=n;i++){
            dp[i][m]=1;
        }

         
        
        for(long long i=n-1;i>=0;i--)
        {
            for(long long j=m-1;j>=0;j--)
            {
              if(s[i]==t[j])
              {
                long long take=dp[i+1][j+1];
                long long nottake=dp[i+1][j];
                if(take+nottake>INT_MAX) dp[i][j]=INT_MAX;
                else dp[i][j]=take+nottake;
              }
              else 
              {
                dp[i][j]=dp[i+1][j];
              }  
            }
        }
        return dp[0][0];
        
    }
};