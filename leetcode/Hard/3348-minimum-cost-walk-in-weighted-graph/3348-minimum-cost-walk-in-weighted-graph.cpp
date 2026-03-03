/*
 Problem: 3348. Minimum Cost Walk in Weighted Graph
 Language: cpp
 Runtime: 22 ms (60.90%)
 Memory: 204.9 MB (100.00%)
 Tags: Array, Bit Manipulation, Union-Find, Graph Theory
*/
class DSU {
private:
    vector<int> parent, rank, weights;

public:
    DSU(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        weights = vector<int>(n, 131071);
        
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        
        return parent[x];
    }

    void merge(int x, int y, int weight) {
        int nx = find(x);
        int ny = find(y);
        
        if (rank[nx] < rank[ny])
            parent[nx] = ny;
        else
            parent[ny] = nx;
        
        weights[nx] = weights[ny] = weights[nx] & weights[ny] & weight;
        
        if (rank[nx] == rank[ny])
            rank[nx]++;
    }

    int getCost(int x, int y) {
        if (x == y)
            return 0;

        if (find(x) != find(y))
            return -1;
        
        return weights[find(x)];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        DSU uf(n);

        for (const auto& edge : edges)
            uf.merge(edge[0], edge[1], edge[2]);

        vector<int> result;
        
        for (const auto& q : query)
            result.push_back(uf.getCost(q[0], q[1]));
        
        return result;
    }
};