class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if(grid.empty()) return 0;
        int m=grid.size();
        int n=grid[0].size();
        
        int count=0;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && !visited[i][j])
                {
                visited[i][j] = true;
                q.push({grid[i][j],{i,j}});
                long long sum=0;
                while(!q.empty()){
                    int value=q.front().first;
                    int i = q.front().second.first;
                    int j = q.front().second.second;
                    q.pop();
                    sum += grid[i][j];
                    if(i > 0 && grid[i-1][j] != 0 && !visited[i-1][j]){
                        visited[i-1][j] = true;
                        q.push({grid[i-1][j],{i-1,j}});
                        
                    }

                    if(i+1 < m && grid[i+1][j] != 0  && !visited[i+1][j]){
                        visited[i+1][j] = true;
                        q.push({grid[i+1][j],{i+1,j}});
                        
                    }
                    if(j > 0 && grid[i][j-1] != 0  && !visited[i][j-1]){
                        visited[i][j-1] = true;
                        q.push({grid[i][j-1],{i,j-1}});
                        
                    }
                    if(j+1 < n && grid[i][j+1] != 0  && !visited[i][j+1]){
                        visited[i][j+1] = true;
                        q.push({grid[i][j+1],{i,j+1}});
                        
                    }


             
                }
                if(sum%k==0)
                {
                    count++;
                }
                
                }
            }
        }
        return count;
       
        
    }
};