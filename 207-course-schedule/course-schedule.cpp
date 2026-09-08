class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses,0);
        queue<int> q;
        for(auto p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }
        for(int p=0;p < numCourses;p++){
        if(indegrees[p]==0){
            q.push(p);
        }}

        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            count++;
            for(auto x: adj[node]){
                indegrees[x]--;
            
            if(indegrees[x]==0){
                q.push(x);
            }
            }
        }
    
    return count==numCourses ;
      

    
    }


};