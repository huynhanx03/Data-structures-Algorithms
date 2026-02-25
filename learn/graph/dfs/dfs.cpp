class GraphDFS {
private:
    int V;
    vector<vector<int>> adj;

    void dfsRecursive(int u, vector<bool>& visited, vector<int>& parent) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                dfsRecursive(v, visited, parent);
            }
        }
    }

public:
    GraphDFS(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> dfs(int start, int target) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        
        dfsRecursive(start, visited, parent);

        vector<int> path;
        if (visited[target]) {
            for (int v = target; v != start; v = parent[v]) {
                path.push_back(v);
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
        }
        return path;
    }
};
