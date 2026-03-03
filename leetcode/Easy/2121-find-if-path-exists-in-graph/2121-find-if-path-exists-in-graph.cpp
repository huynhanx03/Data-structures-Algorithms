/*
 Problem: 2121. Find if Path Exists in Graph
 Language: cpp
 Runtime: 278 ms (63.43%)
 Memory: 301.8 MB (52.52%)
 Tags: Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
*/
class Solution {
private:
    bool dfs(vector<vector<int>>& v, vector<bool>& check, int source, int destination) {
        if (source == destination) return true;
        
        check[source] = false;

        for (int i = 0; i < v[source].size(); ++i) {
            int next = v[source][i];

            if (!check[next]) continue;

            if (dfs(v, check, next, destination)) return true;
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> v(n, vector<int>());

        for (const auto& edge: edges) {
            int x = edge[0];
            int y = edge[1];

            v[x].push_back(y);
            v[y].push_back(x);
        }

        vector<bool> check(n, true);
        return dfs(v, check, source, destination);
    }
};