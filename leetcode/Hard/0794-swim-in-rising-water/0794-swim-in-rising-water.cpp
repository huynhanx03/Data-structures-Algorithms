/*
 Problem: 794. Swim in Rising Water
 Language: cpp
 Runtime: 6 ms (69.19%)
 Memory: 12.7 MB (85.91%)
 Tags: Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix
*/
class Solution {
public:
    struct Node {
        int time;
        int x, y;
        bool operator>(const Node& other) const { return time > other.time; }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();

            if (cur.x == n - 1 && cur.y == n - 1)
                return cur.time;

            for (auto [dx, dy] : dirs) {
                int nx = cur.x + dx, ny = cur.y + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (visited[nx][ny])
                    continue;

                visited[nx][ny] = true;
                pq.push({max(cur.time, grid[nx][ny]), nx, ny});
            }
        }

        return -1;
    }
};