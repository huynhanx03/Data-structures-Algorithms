/*
 Problem: 2213. Find All People With Secret
 Language: cpp
 Runtime: 199 ms (71.46%)
 Memory: 207.2 MB (99.90%)
 Tags: Depth-First Search, Breadth-First Search, Union-Find, Graph Theory, Sorting
*/
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n,0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] > rank[py]) parent[py] = px;
        else if (rank[px] < rank[py]) parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    void reset(int x) {
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b){ return a[2] < b[2]; });
        
        map<int, vector<pair<int,int>>> sameTime;
        for (auto &m : meetings) sameTime[m[2]].emplace_back(m[0], m[1]);

        UnionFind uf(n);
        uf.unite(0, firstPerson);

        for (auto &[t, ms] : sameTime) {
            for (auto &[x, y] : ms) uf.unite(x, y);
            for (auto &[x, y] : ms) {
                if (!uf.connected(x, 0)) {
                    uf.reset(x);
                    uf.reset(y);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) if (uf.connected(i, 0)) ans.push_back(i);
        return ans;
    }
};
