/*
 Problem: 3238. Minimum Cost to Convert String II
 Language: cpp
 Runtime: 485 ms (46.51%)
 Memory: 168.1 MB (49.41%)
 Tags: Array, String, Dynamic Programming, Graph Theory, Trie, Shortest Path
*/
class Solution {
public:
    long long minimumCost(string source,
                          string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        int n = source.size();
        int m = original.size();

        // group rules by length
        unordered_map<int, vector<int>> rulesByLen;
        for (int i = 0; i < m; ++i) {
            rulesByLen[original[i].size()].push_back(i);
        }

        // bestCost[len][from][to] = min cost
        unordered_map<int,
            unordered_map<string, unordered_map<string, long long>>
        > bestCost;

        // process each length independently
        for (auto& entry : rulesByLen) {
            int L = entry.first;
            auto& idxs = entry.second;

            unordered_map<string, int> id;
            vector<string> nodes;

            auto getId = [&](const string& s) {
                if (!id.count(s)) {
                    int newId = id.size();
                    id[s] = newId;
                    nodes.push_back(s);
                }
                return id[s];
            };

            // collect nodes
            for (int idx : idxs) {
                getId(original[idx]);
                getId(changed[idx]);
            }

            int k = id.size();
            vector<vector<long long>> dist(k, vector<long long>(k, INF));

            for (int i = 0; i < k; ++i)
                dist[i][i] = 0;

            // init edges
            for (int idx : idxs) {
                int u = id[original[idx]];
                int v = id[changed[idx]];
                dist[u][v] = min(dist[u][v], (long long)cost[idx]);
            }

            // Floyd–Warshall
            for (int mid = 0; mid < k; ++mid)
                for (int i = 0; i < k; ++i)
                    if (dist[i][mid] < INF)
                        for (int j = 0; j < k; ++j)
                            if (dist[mid][j] < INF)
                                dist[i][j] = min(dist[i][j],
                                                  dist[i][mid] + dist[mid][j]);

            // store results
            for (int i = 0; i < k; ++i)
                for (int j = 0; j < k; ++j)
                    if (dist[i][j] < INF)
                        bestCost[L][nodes[i]][nodes[j]] = dist[i][j];
        }

        // DP
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            // no change (single char)
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // try substring transforms
            for (auto& entry : bestCost) {
                int L = entry.first;
                if (i + L > n) continue;

                string a = source.substr(i, L);
                string b = target.substr(i, L);

                if (entry.second.count(a) &&
                    entry.second[a].count(b)) {

                    dp[i + L] = min(dp[i + L],
                                    dp[i] + entry.second[a][b]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
