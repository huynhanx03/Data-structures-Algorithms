class Solution {
public:
    static constexpr int NEG_INF = -1e9;

    int budget;
    vector<vector<int>> children;
    vector<int> buyPrice, sellPrice;

    /*
     * Merge two knapsack DP arrays.
     *
     * cur[b]   : max profit using exactly b budget so far
     * child[x] : max profit of a child subtree using x budget
     *
     * We distribute total budget between cur and child.
     */
    void mergeKnapsack(vector<int>& cur, const vector<int>& child) {
        vector<int> next(budget + 1, NEG_INF);

        for (int used = 0; used <= budget; ++used) {
            if (cur[used] < 0) continue;

            for (int take = 0; used + take <= budget; ++take) {
                if (child[take] < 0) continue;
                next[used + take] = max(
                    next[used + take],
                    cur[used] + child[take]
                );
            }
        }
        cur.swap(next);
    }

    /*
     * DFS returns dp[state][b]:
     *
     * state = 0 : parent does NOT buy this employee
     * state = 1 : parent DOES buy this employee (discount available)
     *
     * b = total budget used in the subtree
     * value = maximum profit
     */
    vector<vector<int>> dfs(int u) {
        // Initial DP: no cost, no profit
        vector<vector<int>> dp(2, vector<int>(budget + 1, NEG_INF));
        dp[0][0] = dp[1][0] = 0;

        // Step 1: merge all children (tree knapsack)
        for (int v : children[u]) {
            auto childDP = dfs(v);

            // If we do NOT buy u → children have NO discount
            mergeKnapsack(dp[0], childDP[0]);

            // If we buy u → children get discount
            mergeKnapsack(dp[1], childDP[1]);
        }

        // Step 2: decide whether to buy stock of u
        vector<vector<int>> result(2, vector<int>(budget + 1, NEG_INF));

        // Skip u:
        // children NEVER get discount if u is not bought
        result[0] = dp[0];
        result[1] = dp[0];

        int fullPrice = buyPrice[u];
        int discountPrice = fullPrice / 2;

        // Case 1: parent does NOT buy → u pays full price
        for (int b = fullPrice; b <= budget; ++b) {
            result[0][b] = max(
                result[0][b],
                dp[1][b - fullPrice] + sellPrice[u] - fullPrice
            );
        }

        // Case 2: parent DOES buy → u gets discount
        for (int b = discountPrice; b <= budget; ++b) {
            result[1][b] = max(
                result[1][b],
                dp[1][b - discountPrice] + sellPrice[u] - discountPrice
            );
        }

        return result;
    }

    int maxProfit(
        int n,
        vector<int>& present,
        vector<int>& future,
        vector<vector<int>>& hierarchy,
        int B
    ) {
        budget = B;
        buyPrice = present;
        sellPrice = future;

        // Build company hierarchy tree
        children.assign(n, {});
        for (auto& e : hierarchy) {
            children[e[0] - 1].push_back(e[1] - 1);
        }

        // CEO has no parent → state = 0
        auto rootDP = dfs(0);

        // We can use any budget <= B
        return *max_element(rootDP[0].begin(), rootDP[0].end());
    }
};
