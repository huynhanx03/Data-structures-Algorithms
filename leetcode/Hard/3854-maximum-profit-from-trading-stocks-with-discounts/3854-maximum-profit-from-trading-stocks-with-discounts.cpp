/*
 Problem: 3854. Maximum Profit from Trading Stocks with Discounts
 Language: cpp
 Runtime: 104 ms (88.08%)
 Memory: 106.8 MB (67.44%)
 Tags: Array, Dynamic Programming, Tree, Depth-First Search
*/
class Solution
{
public:
    static constexpr int INF = 1e9;
    int B;
    vector<vector<int>> tree;
    vector<int> present, future;
    vector<vector<vector<int>>> dp;

    vector<int> merge(const vector<int> &A, const vector<int> &B2)
    {
        vector<int> C(B + 1, -INF);
        for (int i = 0; i <= B; i++)
        {
            if (A[i] < 0) continue;
            for (int j = 0; i + j <= B; j++)
            {
                if (B2[j] < 0) continue;
                C[i + j] = max(C[i + j], A[i] + B2[j]);
            }
        }
        return C;
    }

    void dfs(int u)
    {
        // merge children once
        vector<int> childNo(B + 1, -INF);
        vector<int> childYes(B + 1, -INF);
        childNo[0] = childYes[0] = 0;

        for (int v : tree[u])
        {
            dfs(v);
            childNo  = merge(childNo,  dp[v][0]);
            childYes = merge(childYes, dp[v][1]);
        }

        dp[u][0].assign(B + 1, -INF);
        dp[u][1].assign(B + 1, -INF);

        // parent NOT bought
        for (int b = 0; b <= B; b++)
        {
            // skip u
            dp[u][0][b] = childNo[b];

            // take u (full price)
            if (b >= present[u])
            {
                dp[u][0][b] = max(dp[u][0][b],
                                  childYes[b - present[u]] +
                                  future[u] - present[u]);
            }
        }

        // parent bought → discount
        int half = present[u] / 2;
        for (int b = 0; b <= B; b++)
        {
            // skip u
            dp[u][1][b] = childNo[b];

            // take u (discount)
            if (b >= half)
            {
                dp[u][1][b] = max(dp[u][1][b],
                                  childYes[b - half] +
                                  future[u] - half);
            }
        }
    }

    int maxProfit(int n, vector<int> &p, vector<int> &f,
                  vector<vector<int>> &hierarchy, int budget)
    {
        B = budget;
        present = p;
        future = f;

        tree.assign(n, {});
        for (auto &e : hierarchy)
            tree[e[0] - 1].push_back(e[1] - 1);

        dp.assign(n, vector<vector<int>>(2));
        dfs(0);

        int ans = 0;
        for (int b = 0; b <= B; b++)
            ans = max(ans, dp[0][0][b]);
        return ans;
    }
};
