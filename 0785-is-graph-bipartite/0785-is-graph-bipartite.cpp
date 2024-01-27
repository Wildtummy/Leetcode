class Solution {
    private:
    bool check(int i,vector<vector<int>>& graph,vector<int>& color){
       
        color[i]=0;
        queue <int> q;
        q.push(i);
        while(!q.empty()){

            for(auto k:graph[q.front()]){
                if(color[q.front()]==color[k]){return false;}
                else if(color[k]==-1){
                    color[k]= !color[q.front()];
                q.push(k);
                }
            }
            q.pop();
        }
      return true;  
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> color(graph.size(),-1);
        for (int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(check(i,graph,color)==false){return false;}}
        }
        return true;
    }
};