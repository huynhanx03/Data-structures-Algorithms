/*
 Problem: 3889. Minimum Cost Path with Teleportations
 Language: cpp
 Runtime: 2425 ms (6.22%)
 Memory: 268.2 MB (31.27%)
 Tags: Array, Dynamic Programming, Matrix
*/
class Solution {
public:
    struct Node {
        int cost, id, used;
        bool operator>(const Node& o) const {
            return cost > o.cost;
        }
    };

    int minCost(vector<vector<int>>& grid, int k) {
        int h = grid.size(), w = grid[0].size();
        int cnt = h * w;
        const int INF = 1e9;

        vector<pair<int,int>> cells;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cells.push_back({grid[i][j], i * w + j});
        sort(cells.begin(), cells.end());

        vector<vector<int>> dist(k + 1, vector<int>(cnt, INF));
        vector<vector<char>> usedTp(k + 1, vector<char>(cnt, 0));
        vector<int> nextCell(k + 1, 0);

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();

            int cost = cur.cost;
            int id = cur.id;
            int used = cur.used;

            if (cost != dist[used][id]) continue;

            int x = id / w, y = id % w;

            if (y + 1 < w) {
                int v = id + 1;
                int nc = cost + grid[x][y + 1];
                if (nc < dist[used][v]) {
                    dist[used][v] = nc;
                    pq.push({nc, v, used});
                }
            }

            if (x + 1 < h) {
                int v = id + w;
                int nc = cost + grid[x + 1][y];
                if (nc < dist[used][v]) {
                    dist[used][v] = nc;
                    pq.push({nc, v, used});
                }
            }

            if (used < k) {
                while (nextCell[used] < cnt &&
                       cells[nextCell[used]].first <= grid[x][y]) {
                    int v = cells[nextCell[used]].second;
                    if (!usedTp[used][v]) {
                        usedTp[used][v] = 1;
                        if (cost < dist[used + 1][v]) {
                            dist[used + 1][v] = cost;
                            pq.push({cost, v, used + 1});
                        }
                    }
                    nextCell[used]++;
                }
            }
        }

        int res = INF;
        for (int i = 0; i <= k; i++)
            res = min(res, dist[i][cnt - 1]);
        return res == INF ? -1 : res;
    }
};
