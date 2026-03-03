/*
 Problem: 4128. Total Waviness of Numbers in Range II
 Language: cpp
 Runtime: 31 ms (69.95%)
 Memory: 9.6 MB (56.16%)
 Tags: Math, Dynamic Programming
*/
class Solution {
private:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[20][2][2][11][11];

    Node dfs(int pos, bool tight, bool st, int p2, int p1) {
        Node &res = dp[pos][tight][st][p2 + 1][p1 + 1];

        if (res.cnt != -1) return res;

        if (pos == s.size()) {
            res = Node{1, 0};
            return res;
        }

        int limit = tight ? (s[pos] - '0') : 9;
        Node ans{0, 0};

        for (int d = 0; d <= limit; ++d) {
            bool nt = tight && (d == limit);
            bool ns = st || d != 0;

            int np2 = p2, np1 = p1;
            long long add = 0;
        
            if (!ns) {
                np2 = -1;
                np1 = -1;
            } else {
                if (p2 != -1 && p1 != -1) {
                    if (p1 > p2 && p1 > d) add = 1;
                    if (p1 < p2 && p1 < d) add = 1;
                }

                np2 = p1;
                np1 = d;
            }

            Node nxt = dfs(pos + 1, nt, ns, np2, np1);
            ans.cnt += nxt.cnt;
            ans.sum += nxt.sum + add * nxt.cnt;
        }

        res = ans;
        return res;
    }

    long long f(long long x) {
        if (x < 0) return 0;
        s = to_string(x);

        memset(dp, -1, sizeof(dp));

        return dfs(0, 1, 0, -1, -1).sum;
    }
    
public:
    long long totalWaviness(long long num1, long long num2) {
        return f(num2) - f(num1 - 1);
    }
};