/*
 Problem: 3708. Zigzag Grid Traversal With Skip
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 32.3 MB (11.76%)
 Tags: Array, Matrix, Simulation
*/
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<int> ans;
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < m; j += 2) {
                    ans.push_back(grid[i][j]);
                }
            } else {
                vector<int> temp;

                for (int j = 1; j < m; j += 2) {
                    temp.push_back(grid[i][j]);
                }

                reverse(temp.begin(), temp.end());

                ans.insert(ans.end(), temp.begin(), temp.end());
            }
        }
        
        return ans;
    }
};