class Dijkstra {
private:
    int V;
    vector<vector<pair<int, int>>> adj; // v, weight
    const int INF = 1e9;

public:
    Dijkstra(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); 
    }

    vector<int> shortestPath(int start) {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int current_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (current_dist > dist[u]) continue;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};