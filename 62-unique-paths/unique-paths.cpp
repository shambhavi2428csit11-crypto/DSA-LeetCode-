class Solution {
public:
    // int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        // if(i==m-1 && j==n-1){
        //     return 1;
        // }
    //     else if(i>=m || j>=n){
    //         return 0;
    //     }
        // if(dp[i][j]!=-1){
        //     return dp[i][j];
        // }
        // int down=solve(i+1,j,m,n,dp);
        // int right=solve(i,j+1,m,n,dp);
        // return dp[i][j]=down+right;
    // }
    int uniquePaths(int m, int n) {
        vector<int>next(n+1,0);
        for(int i=m-1;i>=0;i--){
            vector<int>curr(n+1,0);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) curr[j]=1;
                else{
                    int down=next[j];
                    int right=curr[j+1];
                    curr[j]=down+right;
                }
            }  
            next=curr;
        }
        return next[0];
    }
};