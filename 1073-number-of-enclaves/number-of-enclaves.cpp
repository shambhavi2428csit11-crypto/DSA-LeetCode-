class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0||j==0||i==n-1||j==m-1) && grid[i][j]==1){
                q.push({i,j});
                grid[i][j]='#';
            }

        }
       } 
       while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        if(r-1>=0 && grid[r-1][c]==1){
            q.push({r-1,c});
            grid[r-1][c]=0;    
        }
        if(c-1>=0 && grid[r][c-1]==1){
            q.push({r,c-1});
            grid[r][c-1]=0;    
        }
        if(r+1<n && grid[r+1][c]==1){
            q.push({r+1,c});
            grid[r+1][c]=0;    
        }
        if(c+1<m && grid[r][c+1]==1){
            q.push({r,c+1});
            grid[r][c+1]=0;    
        }
       }
       int count=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                count++;
            }
        }

        }
        return count;
    }

};