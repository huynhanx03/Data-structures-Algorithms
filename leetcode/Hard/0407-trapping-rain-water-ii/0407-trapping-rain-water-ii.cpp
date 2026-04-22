/*
 Problem: 407. Trapping Rain Water II
 Language: cpp
 Runtime: 98 ms (20.42%)
 Memory: 28.9 MB (24.31%)
 Tags: Array, Breadth-First Search, Heap (Priority Queue), Matrix
*/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            vis[i][0] = vis[i][n - 1] = true;
        }
        
        for (int j = 1; j < n - 1; ++j) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            vis[0][j] = vis[m - 1][j] = true;
        }
        
        int ans = 0;
        int d[5] = {-1, 0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            
            int h = cur[0], x = cur[1], y = cur[2];
            
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k], ny = y + d[k + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
                
                vis[nx][ny] = true;
                ans += max(0, h - heightMap[nx][ny]);
                pq.push({max(h, heightMap[nx][ny]), nx, ny});
            }
        }
        
        return ans;
    }
};