class Solution {
public:
// int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
//     if(i==triangle.size()-1){
//         return triangle[i][j];
//     }
//     // if(dp[i][j] != INT_MAX) {
//     //         return dp[i][j];
//     //     }
//     // int down=solve(i+1,j,triangle,dp);
//     // int side=solve(i+1,j+1,triangle,dp);
//     // return dp[i][j]=triangle[i][j]+min(down,side);



// }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];}
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
               
                int down=dp[i+1][j];
                int side=dp[i+1][j+1];
                dp[i][j]=triangle[i][j]+min(down,side);
                
            }
        }
        return dp[0][0]; 
        
    }
};