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
        vector<long long>next(m+1,0);
        next[m]=1;
         
        
        for(long long i=n-1;i>=0;i--)
        {
            vector<long long>curr(m+1,0); 
            curr[m]=1;  
            for(long long j=m-1;j>=0;j--)
            {
              if(s[i]==t[j])
              {
                long long take=next[j+1];
                long long nottake=next[j];
                if(take>LLONG_MAX-nottake) curr[j]=LLONG_MAX;
                else curr[j]=take+nottake;
              }
              else 
              {
                curr[j]=next[j];
              }  
            }
            next=curr;
        }
        return next[0];
        
    }
};