class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    void dfs(int i,int j,vector<vector<char>>& board, vector<vector<bool>>& vis){
        vis[i][j]=1;
        for (int a=0;a<4;a++){
            int nx=i+dx[a];
            int ny=j+dy[a];
            if(nx<0 || ny<0 || nx>=board.size() || ny>=board[0].size() || vis[nx][ny]){continue;}
            if(board[nx][ny]=='O'){board[nx][ny]='c';dfs(nx,ny,board,vis);}
            
            
        }
        
    }
    void solve(vector<vector<char>>& board) {

        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),0));
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){board[0][i]='c';dfs(0,i,board,vis);}
             if(board[board.size()-1][i]=='O'){board[board.size()-1][i]='c';dfs(board.size()-1,i,board,vis);}
        }
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){board[i][0]='c';dfs(i,0,board,vis);}
             if(board[i][board[0].size()-1]=='O'){board[i][board[0].size()-1]='c';dfs(i,board[0].size()-1,board,vis);}
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='c'){board[i][j]='O';}
                else{board[i][j]='X';}
                
            }
        }
    }
};