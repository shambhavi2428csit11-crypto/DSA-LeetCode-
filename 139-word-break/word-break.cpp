class Solution {
public:
    bool solve(int index,string &s,vector<string>& wordDict, vector<int>& dp)
    {   if(index==s.length()){
        return true;
    }
    if (dp[index] != -1) {
            return dp[index];
        }
        for(int i=0;i<wordDict.size();i++){
            string word=wordDict[i];
            int length=word.length();
            if(s.substr(index,length)==word){
                if(solve(index+length,s,wordDict,dp)){
                    return dp[index]=true;
                }
            }

        }
        return dp[index]=false;
    }
           
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<int> dp(n,-1);
        return solve(0,s,wordDict,dp);

    }
};