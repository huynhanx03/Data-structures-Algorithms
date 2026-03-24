/*
 Problem: 3031. Construct Product Matrix
 Language: cpp
 Runtime: 36 ms (60.15%)
 Memory: 140.3 MB (53.87%)
 Tags: Array, Matrix, Prefix Sum
*/
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        const int k = n * m;
        const long long MOD = 12345;

        vector<long long> arr;
        arr.reserve(k);

        for (const auto& row : grid)
            for (const auto& x : row)
                arr.push_back(x % MOD);

        vector<long long> prefix(k, 1);
        for (int i = 1; i < k; ++i)
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;

        vector<vector<int>> res(n, vector<int>(m));
        long long suffix = 1;

        for (int i = k - 1; i >= 0; --i) {
            res[i / m][i % m] = (prefix[i] * suffix) % MOD;
            suffix = (suffix * arr[i]) % MOD;
        }

        return res;
    }
};