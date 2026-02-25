class LCA {
private:
    int n;
    int maxLevel;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> adj;

    void dfs(int u, int p) {
        up[u][0] = p;
        for (int i = 1; i <= maxLevel; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }

public:
    LCA(int nodes) {
        n = nodes;
        maxLevel = ceil(log2(n));
        adj.resize(n + 1);
        depth.resize(n + 1, 0);
        up.assign(n + 1, vector<int>(maxLevel + 1, 0));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int root = 1) {
        dfs(root, root);
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = maxLevel; i >= 0; --i) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = maxLevel; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }
    
    int getDistance(int u, int v) {
        int lcaNode = getLCA(u, v);
        return depth[u] + depth[v] - 2 * depth[lcaNode];
    }
};