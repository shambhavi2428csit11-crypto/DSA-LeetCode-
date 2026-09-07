class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int oldcolor=image[sr][sc];
        if(oldcolor==color){
            return image;
        }
        queue<pair<int,int>> q;
        
        
            image[sr][sc]=color;
            q.push({sr,sc});
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            if(r-1>=0 && image[r-1][c]==oldcolor){
                image[r-1][c]=color;
                q.push({r-1,c});
            }
            if(r+1<n && image[r+1][c]==oldcolor){
                image[r+1][c]=color;
                q.push({r+1,c});
            }
            if(c-1>=0 && image[r][c-1]==oldcolor){
                image[r][c-1]=color;
                q.push({r,c-1});
            }
            if(c+1<m && image[r][c+1]==oldcolor){
                image[r][c+1]=color;
                q.push({r,c+1});
            }
            
            }

        }
        
          
                    
          return image;      
            
        
        
    }
};