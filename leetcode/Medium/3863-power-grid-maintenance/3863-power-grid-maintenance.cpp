/*
 Problem: 3863. Power Grid Maintenance
 Language: cpp
 Runtime: 234 ms (69.68%)
 Memory: 353.3 MB (62.86%)
 Tags: Array, Hash Table, Depth-First Search, Breadth-First Search, Union-Find, Graph Theory, Heap (Priority Queue), Ordered Set
*/
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n+1), rank(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto &edge : connections) {
            dsu.unite(edge[0], edge[1]);
        }

        vector<bool> online(c + 1, true);
        unordered_map<int, set<int>> gridStations;
        for (int i = 1; i <= c; ++i) {
            int root = dsu.find(i);
            gridStations[root].insert(i);
        }

        vector<int> res;
        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);

            if (type == 1) {
                if (online[x]) {
                    res.push_back(x);
                } else {
                    if (gridStations[root].empty()) res.push_back(-1);
                    else res.push_back(*gridStations[root].begin());
                }
            } 
            else if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    gridStations[root].erase(x);
                }
            }
        }

        return res;
    }
};
