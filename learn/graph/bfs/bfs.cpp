class GraphBFS {
private:
    int V;
    vector<vector<int>> adj;

public:
    GraphBFS(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> bfs(int start, int target) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == target) break;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

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
