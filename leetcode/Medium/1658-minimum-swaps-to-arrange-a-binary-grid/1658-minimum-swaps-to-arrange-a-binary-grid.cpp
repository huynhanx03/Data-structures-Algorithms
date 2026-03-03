/*
 Problem: 1658. Minimum Swaps to Arrange a Binary Grid
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 30 MB (66.25%)
 Tags: Array, Greedy, Matrix
*/
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                cnt++;
            }
            zeros[i] = cnt;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int need = n - i - 1;
            int j = i;

            while (j < n && zeros[j] < need) j++;
            if (j == n) return -1;

            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};