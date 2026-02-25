class Prim {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Prim(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int mstCost(int start = 0) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inMST(V, false);
        int totalWeight = 0;

        pq.push({0, start});

        while (!pq.empty()) {
            int weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            totalWeight += weight;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int edgeWeight = edge.second;

                if (!inMST[v]) {
                    pq.push({edgeWeight, v});
                }
            }
        }

        return totalWeight;
    }
};