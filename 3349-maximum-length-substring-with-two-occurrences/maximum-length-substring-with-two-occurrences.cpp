class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;

        int n=s.size();
        int i=0;
        int j=0;
        int ms=0;
        while(j<n){
            if(mp[s[j]]<2){
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