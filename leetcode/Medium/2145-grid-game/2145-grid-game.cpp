/*
 Problem: 2145. Grid Game
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 66.7 MB (60.31%)
 Tags: Array, Matrix, Prefix Sum
*/
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = 0, bottomSum = 0;
        long long ans = 5e9;
        int n = grid[0].size();

        for (int i = 0; i < n; ++i)
            topSum += grid[0][i];

        for (int i = 0; i < n; ++i) {
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }

        return ans;
    }
};