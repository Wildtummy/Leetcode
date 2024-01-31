class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() )return 0;
        else return 1;
    }
   vector <int> dx={1,1,0,-1,-1,-1,0,1};
     vector <int> dy={0,-1,-1,-1,0,1,1,1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> d(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        if(grid[0][0] || grid[grid.size()-1][grid.size()-1])return -1;
        d[0][0]=1;
       set<pair<int,pair<int,int>>> q;
        q.insert({1,{0,0}}); //wt,node
        
        while(!q.empty()){
            
            int wt=(*q.begin()).first;
            int i=(*q.begin()).second.first;
            int j=(*q.begin()).second.second;
               vis[i][j]=1;
            q.erase(*q.begin());
            for(int x=0;x<8;x++){
                int a=i+dx[x];int b=j+dy[x];
                if(check(a,b,grid) && !vis[a][b]){
                    if(d[a][b]>wt+1 && !grid[a][b]){d[a][b]=wt+1;
                        q.insert({wt+1,{a,b}});}
                    
                }
            }
            
        }
        if(d[grid.size()-1][grid[0].size()-1]==INT_MAX)return -1;
        return d[grid.size()-1][grid[0].size()-1];
    }
};