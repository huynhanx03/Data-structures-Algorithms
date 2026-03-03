/*
 Problem: 52. N-Queens II
 Language: cpp
 Runtime: 3 ms (38.22%)
 Memory: 7.6 MB (100.00%)
 Tags: Backtracking
*/
class Solution {
public:
    int ans = 0;
    vector <int> c;
    vector <int> c1;
    vector <int> c2;

    int totalNQueens(int n) {
        if (n == 1)
            return 1;
        
        if (n <= 3)
            return 0;

        c.resize(n + 5, 0);
        c1.resize(2 * n + 5, 0);
        c2.resize(2 * n + 5, 0);

        backtrack(0, n);

        return ans;
    }

    void backtrack(int idx, int& n) {
        if (idx == n) {
            ++ans;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (c[i] || c1[i + idx] || c2[i - idx + n - 1])
                continue;

            c[i] = 1;
            c1[i + idx] = 1;
            c2[i - idx + n - 1] = 1;
            
            backtrack(idx + 1, n);

            c[i] = 0;
            c1[i + idx] = 0;
            c2[i - idx + n - 1] = 0;
        }
    }
};