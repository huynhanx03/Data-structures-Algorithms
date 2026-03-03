/*
 Problem: 2564. Most Profitable Path in a Tree
 Language: cpp
 Runtime: 167 ms (40.12%)
 Memory: 168.7 MB (26.08%)
 Tags: Array, Tree, Depth-First Search, Breadth-First Search, Graph Theory
*/
class Solution {
private:
    vector<int> timeBob;
    vector<bool> checkBob;

    bool dfsBob(int source, int ti, vector<vector<int>>& graph) {
        timeBob[source] = ti;
        checkBob[source] = false;

        if (source == 0)
            return true;

        for (int i = 0; i < graph[source].size(); ++i) {
            int next = graph[source][i];

            if (checkBob[next] && dfsBob(next, ti + 1, graph))
                return true;
        }

        timeBob[source] = -1;

        return false;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = edges.size() + 1;
        timeBob.resize(n, -1);
        checkBob.resize(n, true);

        vector<vector<int>> graph(n, vector<int>());

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfsBob(bob, 0, graph);

        int ans = -1e9;

        queue<vector<int>> qu;

        // {pos, time, value}
        qu.push({0, 0, 0});

        vector<bool> checkAlice(n + 5, true);

        // bfs Alice
        while (!qu.empty()) {
            int pos = qu.front()[0];
            int ti = qu.front()[1];
            int v = qu.front()[2];
            qu.pop();

            checkAlice[pos] = false;

            if (timeBob[pos] == -1) {
                v += amount[pos];
            } else {
                if (ti < timeBob[pos]) {
                    v += amount[pos];
                } else if (ti == timeBob[pos]) {
                    v += amount[pos] / 2;
                }
            }

            if (graph[pos].size() == 1 && pos != 0) {
                ans = max(ans, v);
            }

            for (int i = 0; i < graph[pos].size(); ++i) {
                int next = graph[pos][i];

                if (checkAlice[next]) {
                    qu.push({next, ti + 1, v});
                }
            }
        }

        return ans;
    }
};