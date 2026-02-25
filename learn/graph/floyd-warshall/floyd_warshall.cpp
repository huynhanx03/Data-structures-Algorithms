class FloydWarshall {
private:
    int V;
    vector<vector<int>> dist;
    const int INF = 1e9;

public:
    FloydWarshall(int vertices) {
        V = vertices;
        dist.assign(V, vector<int>(V, INF));
        for (int i = 0; i < V; ++i) {
            dist[i][i] = 0;
        }
    }

    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight;
    }

    void shortestPaths() {
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    int getDistance(int u, int v) {
        return dist[u][v];
    }
    
    bool hasNegativeCycle() {
        for (int i = 0; i < V; ++i) {
            if (dist[i][i] < 0) {
                return true;
            }
        }
        return false;
    }
};