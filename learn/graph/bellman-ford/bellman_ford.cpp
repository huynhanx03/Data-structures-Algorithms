struct Edge {
    int source, target, weight;
};

class BellmanFord {
private:
    int V;
    vector<Edge> edges;
    const int INF = 1e9;

public:
    BellmanFord(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // Returns a distance array, or an empty vector if negative cycle is detected
    vector<int> shortestPath(int start) {
        vector<int> dist(V, INF);
        dist[start] = 0;

        for (int i = 0; i < V - 1; ++i) {
            for (auto edge : edges) {
                int u = edge.source;
                int v = edge.target;
                int weight = edge.weight;

                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        for (auto edge : edges) {
            int u = edge.source;
            int v = edge.target;
            int weight = edge.weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                return {}; // Negative weight cycle
            }
        }

        return dist;
    }
};