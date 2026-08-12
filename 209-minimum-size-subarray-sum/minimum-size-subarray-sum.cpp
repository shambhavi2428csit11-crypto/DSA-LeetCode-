class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ms=INT_MAX;
        int sum=nums[j];
        while(j<n){
            if(sum<target)
            {
                
                j++;
                if(j<n)
                {sum+=nums[j];}
            }
            else if(sum>=target)
            {
                ms=min(ms,j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        if(ms==INT_MAX)
        {
            return 0;
        }
        return ms;
    }
};