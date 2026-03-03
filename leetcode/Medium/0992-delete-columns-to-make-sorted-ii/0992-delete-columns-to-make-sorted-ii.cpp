/*
 Problem: 992. Delete Columns to Make Sorted II
 Language: cpp
 Runtime: 4 ms (14.66%)
 Memory: 12.7 MB (98.18%)
 Tags: Array, String, Greedy
*/
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<bool> sorted(n - 1, false);
        int ans = 0;

        for (int col = 0; col < m; col++) {
            bool bad = false;

            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ans++; 
            } else {
                for (int i = 0; i < n - 1; i++) {
                    if (strs[i][col] < strs[i + 1][col]) {
                        sorted[i] = true;
                    }
                }
            }
        }

        return ans;
    }
};
