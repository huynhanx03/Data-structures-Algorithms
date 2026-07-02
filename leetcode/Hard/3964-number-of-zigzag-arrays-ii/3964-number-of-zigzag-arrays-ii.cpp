/*
 Problem: 3964. Number of ZigZag Arrays II
 Language: cpp
 Runtime: 879 ms (15.77%)
 Memory: 73.2 MB (10.52%)
 Tags: Math, Dynamic Programming
*/
class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& a, const Matrix& b) {
        int n = a.size();
        Matrix c(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return c;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int size = 2 * m;

        vector<long long> state(size, 0);

        for (int i = 0; i < m; i++) {
            state[i] = i;
            state[m + i] = m - 1 - i;
        }

        if (n == 2) {
            long long ans = 0;
            for (const auto& x : state) ans = (ans + x) % MOD;
            return ans;
        }

        Matrix T(size, vector<long long>(size, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                T[i][m + j] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                T[m + i][j] = 1;
            }
        }

        Matrix P = power(T, (long long)n - 2);

        vector<long long> finalState(size, 0);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                finalState[i] = (finalState[i] + P[i][j] * state[j]) % MOD;
            }
        }

        long long ans = 0;
        for (const auto& x : finalState) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};