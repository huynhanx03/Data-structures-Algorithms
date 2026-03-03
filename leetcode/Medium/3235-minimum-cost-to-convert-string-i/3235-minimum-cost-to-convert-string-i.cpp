/*
 Problem: 3235. Minimum Cost to Convert String I
 Language: cpp
 Runtime: 29 ms (65.62%)
 Memory: 100.2 MB (52.02%)
 Tags: Array, String, Graph Theory, Shortest Path
*/
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        int n = 26;

        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j],
                                          dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;

        for (int i = 0; i < source.size(); ++i) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (dist[s][t] == INF) {
                return -1;
            }

            totalCost += dist[s][t];
        }

        return totalCost;
    }
};