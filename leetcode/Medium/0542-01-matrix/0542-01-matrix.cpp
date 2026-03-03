/*
 Problem: 542. 01 Matrix
 Language: cpp
 Runtime: 30 ms (21.44%)
 Memory: 34.6 MB (83.92%)
 Tags: Array, Dynamic Programming, Breadth-First Search, Matrix
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize the queue with all the cells containing 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Perform BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    if (dist[newX][newY] > dist[x][y] + 1) {
                        dist[newX][newY] = dist[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        
        return dist;
    }
};