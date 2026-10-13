class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]*nums[i]);
        }
        vector<long long> ans;
        while(!pq.empty()){
            long long value=pq.top();
            pq.pop();
            
            ans.push_back(value);


        }
        long long start=0;
        long long end=ans.size()-1;
        long long mid=(start+end)/2;
        long long sum1=0;
        long long sum2=0;
        for(int j=0;j<mid+1;j++){
            sum1+=ans[j];
        }
        for(int k=mid+1;k<ans.size();k++){
            sum2+=ans[k];
        }
        long long ans1=sum1-sum2;
        return ans1;
        

    }
};