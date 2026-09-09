class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                    board[i][j]='#';
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r-1 >=0 && board[r-1][c]=='O'){
                q.push({r-1,c});
                board[r-1][c]='#';
            }
            if(r+1<n && board[r+1][c]=='O'){
                q.push({r+1,c});
                board[r+1][c]='#';
            }
            if(c-1>=0 && board[r][c-1]=='O'){
                q.push({r,c-1});
                board[r][c-1]='#';
            }
            if(c+1<m && board[r][c+1]=='O'){
                q.push({r,c+1});
                board[r][c+1]='#';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(board[i][j]=='O'){
                        board[i][j]='X';
                    }
                    if(board[i][j]=='#'){
                        board[i][j]='O';
                    }
                    }
            }
        
    }
};