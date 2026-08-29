class Graph {
private:
    int numNodes;
    // Adjacency list storing pairs of {neighbor, cost}
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int n, vector<vector<int>>& edges) {
        numNodes = n;
        adj.resize(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // Min-priority queue storing {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(numNodes, INT_MAX);

        dist[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Destination reached
            if (u == node2) {
                return d;
            }

            // Skip outdated shorter distance entries
            if (d > dist[u]) {
                continue;
            }

            for (const auto& [v, cost] : adj[u]) {
                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */