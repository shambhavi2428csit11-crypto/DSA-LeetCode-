class Solution {
public:

    int solve(int i, int j, string &str1, string &str2,
              vector<vector<int>>& dp) {

        // Base case
        if(i == str1.size()) {
            return str2.size() - j;
        }

        if(j == str2.size()) {
            return str1.size() - i;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters same
        if(str1[i] == str2[j]) {
            return dp[i][j] =
                1 + solve(i + 1, j + 1, str1, str2, dp);
        }

        // Characters different
        int take1 =
            1 + solve(i + 1, j, str1, str2, dp);

        int take2 =
            1 + solve(i, j + 1, str1, str2, dp);

        return dp[i][j] = min(take1, take2);
    }


    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        solve(0, 0, str1, str2, dp);

        string ans = "";

        int i = 0;
        int j = 0;

        while(i < n && j < m) {

            if(str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }

            else {

                int take1 = solve(i + 1, j, str1, str2, dp);
                int take2 = solve(i, j + 1, str1, str2, dp);

                if(take1 <= take2) {
                    ans += str1[i];
                    i++;
                }
                else {
                    ans += str2[j];
                    j++;
                }
            }
        }

        // Remaining characters
        while(i < n) {
            ans += str1[i];
            i++;
        }

        while(j < m) {
            ans += str2[j];
            j++;
        }

        return ans;
    }
};