class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=INT_MIN;
        int more=0;
        int n=nums.size();
        int mini=INT_MAX;
        int less=0;

        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                 more=i;
            }
            if(mini>nums[i])
            {
                mini=nums[i];
                less=i;
            }
        }


        int ans=min(less,more);
        int out=max(less,more);
        int me=ans+1;
        int you=n-out;
        int dora=min(me,you);
        int result=dora;
        int add;
        if(dora==me)
        {
            add=min(you,out+1-me);
        }
        else
        {
            add=min(me,out-me+1);
        }
        result+=add;
        return result;
    }
};