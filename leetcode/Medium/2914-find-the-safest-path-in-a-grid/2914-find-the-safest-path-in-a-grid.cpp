/*
 Problem: 2914. Find the Safest Path in a Grid
 Language: cpp
 Runtime: 333 ms (79.30%)
 Memory: 137.7 MB (75.67%)
 Tags: Array, Binary Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix
*/
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        constexpr int d[] = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i];
                int ny = y + d[i + 1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || dist[nx][ny] != -1)
                    continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }

        priority_queue<tuple<int, int, int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.emplace(dist[0][0], 0, 0);
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [safe, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return safe;

            if (safe < best[x][y])
                continue;

            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i];
                int ny = y + d[i + 1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                int nextSafe = min(safe, dist[nx][ny]);

                if (nextSafe <= best[nx][ny])
                    continue;

                best[nx][ny] = nextSafe;
                pq.emplace(nextSafe, nx, ny);
            }
        }

        return 0;
    }
};