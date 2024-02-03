class Solution {
public:
    int ans;
    bool check(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() )return 0;
        else return 1;
    }
    
   vector <int> dx={1,0,-1,0};
     vector <int> dy={0,-1,0,1};
    int minimumEffortPath(vector<vector<int>>& grid) {
         vector<vector<int>> d(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));

  d[0][0]=0;
  queue <pair<int, pair<int,int>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.front().first;
            int i=pq.front().second.first;
            int j=pq.front().second.second;
            pq.pop();
            for(int x=0;x<4;x++){
                int nx=i+dx[x];int ny=j+dy[x];
if(check(nx,ny,grid) && d[nx][ny]>max(d[i][j],abs(grid[nx][ny]-grid[i][j])))
{ d[nx][ny]=max(d[i][j],abs(grid[nx][ny]-grid[i][j]));pq.push({d[nx][ny],{nx,ny}});}
                
                                                                                                           }
            
        }
      
     return d[grid.size()-1][grid[0].size()-1];   
    }
};