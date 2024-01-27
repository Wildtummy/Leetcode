class Solution {
    private:
    vector<int> parent;
    vector<int> sz;
    void make_set(int v){
        parent [v]=v;
        sz[v]=1;
    }
    int find_set(int v){
        if(v==parent[v])return v;
        return parent[v]=find_set(parent[v]);
        
    }
    void union_set(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(sz[a]<sz[b]){swap(a,b);}
        parent[b]=a;
        sz[a]+=sz[b];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(1001);
        sz.resize(1001);
        for(int i=0;i<1001;i++){parent[i]=i;sz[i]=1;}
        for(auto i:edges){
            if(find_set(i[0])==find_set(i[1])){ parent.clear();sz.clear();return{i[0],i[1]};}
            union_set(i[0],i[1]);
        }
        
        return {};
       
    }
};