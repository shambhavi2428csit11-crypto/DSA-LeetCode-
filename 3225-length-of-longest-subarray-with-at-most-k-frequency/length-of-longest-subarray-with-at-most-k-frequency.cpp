class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int ms=0;
        while(i<=j &&j<n){
            if(mp[nums[j]]<k){
                mp[nums[j]]++;
                j++;
                ms= max(ms,j-i);
            }
            else{
                mp[nums[i]]--;
                i++;
            }
        }
        return ms;

    }
};