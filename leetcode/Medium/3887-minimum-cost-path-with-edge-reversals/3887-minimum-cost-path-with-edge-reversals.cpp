/*
 Problem: 3887. Minimum Cost Path with Edge Reversals
 Language: cpp
 Runtime: 419 ms (14.94%)
 Memory: 335.3 MB (13.00%)
 Tags: Graph Theory, Heap (Priority Queue), Shortest Path
*/
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        using ll = long long;
        const ll INF = 1e18;

        vector<vector<pair<int,int>>> out(n), in(n);
        for (auto &e : edges) {
            out[e[0]].push_back({e[1], e[2]});
            in[e[1]].push_back({e[0], e[2]});
        }

        vector<vector<ll>> dist(n, vector<ll>(2, INF));
        priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, u, used] = pq.top();
            pq.pop();
            if (d != dist[u][used]) continue;

            for (auto [v, w] : out[u]) {
                if (dist[v][0] > d + w) {
                    dist[v][0] = d + w;
                    pq.push({dist[v][0], v, 0});
                }
            }

            if (used == 0) {
                for (auto [v, w] : in[u]) {
                    if (dist[v][0] > d + 2LL * w) {
                        dist[v][0] = d + 2LL * w;
                        pq.push({dist[v][0], v, 0});
                    }
                }
            }
        }

        ll res = min(dist[n - 1][0], dist[n - 1][1]);
        return res == INF ? -1 : (int)res;
    }
};
