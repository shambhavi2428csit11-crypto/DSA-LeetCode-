class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
       
        for(int i=0;i<matrix.size();i++){
            pq.push({{matrix[i][0],i},0});
        }
        vector<int> ans;
        while(!pq.empty()){
            int value = pq.top().first.first;
            int s1 = pq.top().first.second;
            int s2 = pq.top().second;
            pq.pop();
            ans.push_back(value);
            s2++;
            if(s2<matrix[s1].size()){
                pq.push({{matrix[s1][s2],s1},s2});
            }
        }
    return ans[k-1];
    }
};