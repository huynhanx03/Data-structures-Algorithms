/*
 Problem: 1396. Count Servers that Communicate
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 26.7 MB (60.54%)
 Tags: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix, Counting
*/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        
        // Count the number of servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        // Count the number of servers that can communicate
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
