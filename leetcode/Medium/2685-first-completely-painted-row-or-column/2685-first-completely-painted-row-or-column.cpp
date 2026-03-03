/*
 Problem: 2685. First Completely Painted Row or Column
 Language: cpp
 Runtime: 160 ms (19.17%)
 Memory: 196.2 MB (9.40%)
 Tags: Array, Hash Table, Matrix
*/
#include <vector>
#include <unordered_map>

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = arr.size();
        int m = mat.size();
        int p = mat[0].size();

        unordered_map<int, int> r, c;
        vector<int> cntr(m, 0), cntc(p, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                int v = mat[i][j];
                r[v] = i;
                c[v] = j;
            }
        }

        for (int i = 0; i < n; ++i) {
            int row = r[arr[i]];
            int col = c[arr[i]];
            if (++cntr[row] == p) return i;
            if (++cntc[col] == m) return i;
        }

        return -1;
    }
};
