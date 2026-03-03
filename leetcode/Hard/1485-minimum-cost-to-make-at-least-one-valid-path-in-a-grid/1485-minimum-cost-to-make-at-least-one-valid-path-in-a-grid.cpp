/*
 Problem: 1485. Minimum Cost to Make at Least One Valid Path in a Grid
 Language: cpp
 Runtime: 4 ms (98.21%)
 Memory: 19.8 MB (58.89%)
 Tags: Array, Breadth-First Search, Graph Theory, Heap (Priority Queue), Matrix, Shortest Path
*/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n);
        for (auto& sdp : dp)
            sdp.resize(m, oo);

        dfs(0, 0, grid);
        
        while (!q.empty()) {
            ++v;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto p = q.front();
                int x = p.first, y = p.second;
                
                q.pop();
                
                for (int j = 0; j < 4; j++)
                    dfs(x + dd[j][0], y + dd[j][1], grid);
            }
        }

        return dp[n - 1][m - 1];
    }

private:
    int n, m;
    int v = 0;
    const int oo = 1e9;
    const int dd[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    queue<pair<int, int>> q;

    vector<vector<int>> dp;

    void dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= n || y < 0 || y >= m || dp[x][y] != oo)
            return;

        dp[x][y] = v;
        q.push({x, y});
        
        int next = grid[x][y] - 1;

        dfs(x + dd[next][0], y + dd[next][1], grid);
    }
};