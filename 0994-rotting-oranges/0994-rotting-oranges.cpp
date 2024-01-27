class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
         int t=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){q.push({{i,j},0});  vis[i][j]=2;}
              
            }
        }
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
       
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            t=q.front().second;
            // cout<<x<<y<<t<<endl;
            
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size()){
                if(grid[nx][ny]==1 && vis[nx][ny]!=2){q.push({{nx,ny},t+1});vis[nx][ny]=2;}}
                
            }
            }
            
            for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               
                if(grid[i][j]==1 && vis[i][j]!=2){return -1;}
              
            }
        }
            
        return t;
        }
        
};