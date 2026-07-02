/*
 Problem: 3558. Find a Safe Walk Through a Grid
 Language: cpp
 Runtime: 35 ms (34.05%)
 Memory: 36.9 MB (36.52%)
 Tags: Array, Breadth-First Search, Graph Theory, Heap (Priority Queue), Matrix, Shortest Path
*/
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        health -= grid[0][0];
        if (health <= 0) return false;

        vector<vector<int>> best(n, vector<int>(m, -1));
        queue<tuple<int, int, int>> q;

        q.push({0, 0, health});
        best[0][0] = health;

        int dd[] = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            auto [x, y, hp] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1) return true;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dd[k];
                int ny = y + dd[k + 1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int nhp = hp - grid[nx][ny];

                if (nhp <= 0 || nhp <= best[nx][ny])
                    continue;

                best[nx][ny] = nhp;
                q.push({nx, ny, nhp});
            }
        }

        return false;
    }
};