class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});

                }
                else if(grid[i][j]==1){
                        fresh++;
                    }
                }
            }
        
        int time=0;
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r-1>=0 && grid[r-1][c]==1) {
                    grid[r-1][c]=2;
                    fresh--;
                    q.push({r-1,c});
                }

                if(r+1<n && grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    fresh--;
                    q.push({r+1,c});
                }
                
                if(c+1<m && grid[r][c+1]==1){
                    grid[r][c+1]=2;
                    fresh--;
                    q.push({r,c+1});
                }
                
                if(c-1>=0 && grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    fresh--;
                    q.push({r,c-1});
                }


            }
            time++;
            
            
        }
        if(fresh>0){
            return -1;
        }
        return time;
    }
};