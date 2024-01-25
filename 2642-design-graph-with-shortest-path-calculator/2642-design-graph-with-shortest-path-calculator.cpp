class Graph {
public:
 vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto i: edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
         return dijkstra(node1, node2);
    }
    private:
    int dijkstra(int start, int end) {
        int n = adj.size();
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;
        set<pair<int,int>>s;
        s.insert({0,start});
        while(!s.empty()){
int currentNode = s.begin()->second;
            int currentCost = s.begin()->first;
            s.erase(s.begin());

if (currentCost > distances[currentNode])
                continue;
                if(currentNode == end)
                return currentCost ;

                for (auto edge : adj[currentNode]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newRouteCost = edgeLength + distances[currentNode];

        if (distances[neighbor] > newRouteCost) {
                    distances[neighbor] = newRouteCost;
                    s.insert({newRouteCost, neighbor});}
                }

        }
            return ((distances[end] == INT_MAX) ? -1 : distances[end]);

    }

};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */