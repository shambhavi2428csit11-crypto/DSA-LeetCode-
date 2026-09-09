class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});

                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r-1>=0 && mat[r-1][c]==-1){
                mat[r-1][c]=mat[r][c]+1;
                q.push({r-1,c});
            }
            if(r+1<n && mat[r+1][c]==-1){
                mat[r+1][c]=mat[r][c]+1;
                q.push({r+1,c});
            }
            if(c-1>=0 && mat[r][c-1]==-1){
                mat[r][c-1]=mat[r][c]+1;
                q.push({r,c-1});
            }
            if(c+1<m && mat[r][c+1]==-1){
                mat[r][c+1]=mat[r][c]+1;
                q.push({r,c+1});
            }
        }
        return mat;
    }
};