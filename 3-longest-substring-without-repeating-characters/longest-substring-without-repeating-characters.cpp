class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int ms=0;
        int i=0;
        int j=0;
        while( j<n){
            if(mp[s[j]]<1){
                mp[s[j]]++;
                j++;
                ms=max(ms,j-i);
            }
            else{
                mp[s[i]]--;
                i++;

            }
        }
        return ms;
    }
};