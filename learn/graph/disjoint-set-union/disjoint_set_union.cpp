class DSU {
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int u) {
        if (u == parent[u]) return u;
        // Path compression
        return parent[u] = findSet(parent[u]);
    }

    void unionSet(int u, int v) {
        int rootU = findSet(u);
        int rootV = findSet(v);

        if (rootU != rootV) {
            // Union by size
            if (sz[rootU] < sz[rootV]) {
                swap(rootU, rootV);
            }
            parent[rootV] = rootU;
            sz[rootU] += sz[rootV];
        }
    }

    bool isConnected(int u, int v) {
        return findSet(u) == findSet(v);
    }
};