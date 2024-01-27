class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    void dfs(int i,int j,vector<vector<int>>& board, vector<vector<bool>>& vis){
        vis[i][j]=1;
        for (int a=0;a<4;a++){
            int nx=i+dx[a];
            int ny=j+dy[a];
            if(nx<0 || ny<0 || nx>=board.size() || ny>=board[0].size() || vis[nx][ny]){continue;}
            if(board[nx][ny]==1){board[nx][ny]=-1;dfs(nx,ny,board,vis);}
            
            
        }
        
    }
    int numEnclaves(vector<vector<int>>& board) {
         vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),0));
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]==1){board[0][i]=-1;dfs(0,i,board,vis);}
             if(board[board.size()-1][i]==1){board[board.size()-1][i]=-1;dfs(board.size()-1,i,board,vis);}
        }
        for(int i=0;i<board.size();i++){
            if(board[i][0]==1){board[i][0]=-1;dfs(i,0,board,vis);}
             if(board[i][board[0].size()-1]==1){board[i][board[0].size()-1]=-1;dfs(i,board[0].size()-1,board,vis);}
        }
        int ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1){ans++;}
             if(board[i][j]==-1){board[i][j]=1;}
                
            }
        }
        return ans;
    }
};