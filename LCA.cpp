#include "bits/stdc++.h"

using namespace std;

const int mxN = 1e5+5;

int n, par[mxN], up[mxN][20], h[mxN];

vector <int> g[mxN];

void preprocess() {
    for (int i = 1; i <= n; ++i) up[i][0] = par[i];

    for (int j = 1; j <= 15; ++j) 
        for (int i = 1; i <= n; ++i)
            up[i][j] = up[up[i][j - 1]][j - 1];
}

int ancestor_k(int u, int k) {
    for (int i = 0; (1 << i) <= k; ++i) 
        if (k >> i & 1) u = up[u][i]; // lấy tổ tiên theo bit 1

    return u;
}

void dfs(int u) {
    for (int v : g[u]) {
        if (v == up[u][0]) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;

        // -->> preprocess <<--
    
        dfs(v);
    }
}

int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);

        int k = h[u] - h[v];

        // ancestor_k
        for (int i = 0; (1 << i) <= k; ++i) 
            if (k >> i & 1) u = up[u][i];
    }

    if (u == v) return u;

    int k = __lg(h[u]);

    for (int i = k; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int dist(int u, int v) {
    int p = lca(u, v);
    return h[u] + h[v] - 2 * h[p];
}

int32_t main()
{

}