/*
 Problem: 3902. Maximize Spanning Tree Stability with Upgrades
 Language: cpp
 Runtime: 143 ms (45.18%)
 Memory: 294.7 MB (17.77%)
 Tags: Binary Search, Greedy, Union-Find, Graph Theory, Minimum Spanning Tree
*/
class DSU {
private:
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int findSet(int u) {
        return (u == parent[u]) ? u : parent[u] = findSet(parent[u]);
    }

    bool unionSet(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

class Solution {
private:
    bool can(int n, const vector<vector<int>>& edges, int k, long long x) {
        DSU dsu(n);
        int used = 0, upgrades = 0;

        for (const auto& e : edges) {
            if (e[3]) {
                if (e[2] < x) return false;
                if (!dsu.unionSet(e[0], e[1])) return false;
                ++used;
            }
        }

        for (const auto& e : edges) {
            if (e[3]) continue;
            if (e[2] >= x && dsu.unionSet(e[0], e[1])) ++used;
        }

        for (const auto& e : edges) {
            if (e[3]) continue;
            if (e[2] < x && ((long long)e[2] << 1) >= x && upgrades < k) {
                if (dsu.unionSet(e[0], e[1])) {
                    ++upgrades;
                    ++used;
                }
            }
        }

        return used == n - 1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        long long l = 0, r = 2000000000;
        int ans = -1;

        while (l <= r) {
            long long mid = l + ((r - l) >> 1);
            if (can(n, edges, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};