/*
 Problem: 4124. Count Good Integers on a Grid Path
 Language: cpp
 Runtime: 46 ms (16.27%)
 Memory: 28.2 MB (15.13%)
 Tags: None
*/
class Solution {
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        vector<bool> path(16, false);
        int curr = 0;
        path[curr] = true;
        
        for (const auto& d : directions) {
            curr += (d == 'D' ? 4 : 1);
            path[curr] = true;
        }

        auto solve = [&](long long n) -> long long {
            if (n < 0) return 0;
            string s = to_string(n);
            s = string(16 - s.length(), '0') + s;
            
            vector<vector<vector<long long>>> memo(16, vector<vector<long long>>(2, vector<long long>(10, -1)));

            auto dfs = [&](auto& self, int i, bool tight, int last) -> long long {
                if (i == 16) return 1;
                if (memo[i][tight][last] != -1) return memo[i][tight][last];

                long long res = 0;
                int limit = tight ? s[i] - '0' : 9;

                for (int d = 0; d <= limit; ++d) {
                    bool nxt_tight = tight && (d == limit);
                    if (path[i]) {
                        if (d >= last) {
                            res += self(self, i + 1, nxt_tight, d);
                        }
                    } else {
                        res += self(self, i + 1, nxt_tight, last);
                    }
                }
                return memo[i][tight][last] = res;
            };

            return dfs(dfs, 0, true, 0);
        };

        return solve(r) - solve(l - 1);
    }
};