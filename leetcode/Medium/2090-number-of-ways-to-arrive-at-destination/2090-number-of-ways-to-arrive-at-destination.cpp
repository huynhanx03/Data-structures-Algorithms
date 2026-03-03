/*
 Problem: 2090. Number of Ways to Arrive at Destination
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 35 MB (80.78%)
 Tags: Dynamic Programming, Graph Theory, Topological Sort, Shortest Path
*/
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        using pll = pair<long long, int>;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [currentDist, node] = pq.top();
            pq.pop();

            if (currentDist > dist[node])
                continue;

            for (const auto& [neighbor, time] : graph[node]) {
                long long newDist = currentDist + time;

                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.emplace(newDist, neighbor);
                } else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
