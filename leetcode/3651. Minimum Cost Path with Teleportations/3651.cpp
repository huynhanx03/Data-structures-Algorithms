class Solution {
public:
    const int INF = 1e9;

    struct Node {
        int cost, pos, tp;
        bool operator>(const Node& o) const {
            return cost > o.cost;
        }
    };

    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int tot = n * m;

        vector<pair<int,int>> cells;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cells.push_back({grid[i][j], i * m + j});
        sort(cells.begin(), cells.end());

        vector<vector<int>> dist(k + 1, vector<int>(tot, INF));
        vector<vector<bool>> used(k + 1, vector<bool>(tot, false));
        vector<int> ptr(k + 1, 0);

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [cost, pos, tp] = pq.top();
            pq.pop();
            
            if (cost != dist[tp][pos]) continue;

            int x = pos / m, y = pos % m;

            if (y + 1 < m) {
                int v = pos + 1;
                int nc = cost + grid[x][y + 1];
                if (nc < dist[tp][v]) {
                    dist[tp][v] = nc;
                    pq.push({nc, v, tp});
                }
            }

            if (x + 1 < n) {
                int v = pos + m;
                int nc = cost + grid[x + 1][y];
                if (nc < dist[tp][v]) {
                    dist[tp][v] = nc;
                    pq.push({nc, v, tp});
                }
            }

            if (tp < k) {
                while (ptr[tp] < tot && cells[ptr[tp]].first <= grid[x][y]) {
                    int v = cells[ptr[tp]].second;
                    if (!used[tp][v]) {
                        used[tp][v] = true;
                        if (cost < dist[tp + 1][v]) {
                            dist[tp + 1][v] = cost;
                            pq.push({cost, v, tp + 1});
                        }
                    }
                    ++ptr[tp];
                }
            }
        }

        int ans = INF;
        for (int i = 0; i <= k; ++i)
            ans = min(ans, dist[i][tot - 1]);

        return ans == INF ? -1 : ans;
    }
};