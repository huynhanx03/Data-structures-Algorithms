# Intuition
The problem asks for the minimum cost to convert a `source` string to a `target` string by replacing substrings.
There are two main aspects to solve:
1.  **Cost to convert between substrings**: A substring `a` can be converted to `b` directly or indirectly (`a -> c -> b`). This is a shortest path problem on a graph.
2.  **Partitioning the main problem**: We need to decide at each position of `source` whether to keep it as is or replace a substring starting there to minimize the total cost. This is a Dynamic Programming (DP) problem.

# Approach

### Step 1: Build graph and find shortest paths
- Treat each unique string in `original` and `changed` as a node in a graph.
- To handle strings efficiently, use **Rolling Hash** to convert each string into an integer (hash code) and map these hash codes to node IDs from $0, 1, ..., m$.
- Use the **Floyd-Warshall** algorithm to compute the minimum cost between all pairs of strings $(u, v)$.
    - Initialize: `d[u][v]` is the direct cost given in the input.
    - Floyd-Warshall: `d[i][j] = min(d[i][j], d[i][k] + d[k][j])`.

### Step 2: Dynamic Programming (DP) on `source` string
- Let $dp[i]$ be the minimum cost to convert the suffix `source[i...n-1]` to `target[i...n-1]`.
- Goal: Find $dp[0]$.
- Recurrence relation at index $i$ (iterating from $n-1$ down to $0$):
    1.  **Keep**: If `source[i] == target[i]`, we can do nothing, so $dp[i] = dp[i+1]$.
    2.  **Replace**: Try all possible lengths `len` of strings present in `original`.
        - Consider substring `s_sub` from `source` starting at `i` with length `len`.
        - Consider substring `t_sub` from `target` starting at `i` with length `len`.
        - Calculate hash of `s_sub` and `t_sub`.
        - If a path exists from `s_sub` to `t_sub` (found in ID map), update:
          $$dp[i] = \min(dp[i], \text{cost}(s\_sub \to t\_sub) + dp[i+len])$$
- The final result is $dp[0]$. If $dp[0]$ remains infinity, return -1.

# Complexity
- Time complexity: $O(m^3 + n \cdot K)$
- Space complexity: $O(m^2 + n)$

# Code
```cpp []
class Solution {
private:
    long long INF = 4e18;
    unsigned long long P = 131;

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> id;
        unordered_map<unsigned long long, int> mp;
        vector<int> lens;

        auto hstr = [&](const string& s) {
            unsigned long long h = 0;
            for (const auto& c : s) h = h * P + c;
            return h;
        };

        int idx = 0;
        for (const auto& s : original)
            if (id.emplace(s, idx).second) {
                mp[hstr(s)] = idx++;
                lens.push_back(s.size());
            }

        for (const auto& s : changed)
            if (id.emplace(s, idx).second) {
                mp[hstr(s)] = idx++;
                lens.push_back(s.size());
            }

        sort(lens.begin(), lens.end());
        lens.erase(unique(lens.begin(), lens.end()), lens.end());

        vector<vector<long long>> d(idx, vector<long long>(idx, INF));
        for (int i = 0; i < (int)original.size(); ++i) {
            int u = id[original[i]];
            int v = id[changed[i]];
            d[u][v] = min(d[u][v], (long long)cost[i]);
        }

        for (int i = 0; i < idx; ++i) d[i][i] = 0;

        for (int k = 0; k < idx; ++k)
            for (int i = 0; i < idx; ++i)
                if (d[i][k] < INF)
                    for (int j = 0; j < idx; ++j)
                        if (d[k][j] < INF)
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        int n = source.size();
        vector<unsigned long long> hs(n + 1), ht(n + 1), pw(n + 1);
        pw[0] = 1;

        for (int i = 0; i < n; ++i) {
            hs[i + 1] = hs[i] * P + source[i];
            ht[i + 1] = ht[i] * P + target[i];
            pw[i + 1] = pw[i] * P;
        }

        auto get = [&](vector<unsigned long long>& h, int l, int r) {
            return h[r + 1] - h[l] * pw[r - l + 1];
        };

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = (source[i] == target[i]) ? dp[i + 1] : INF;
            for (const auto& len : lens) {
                if (i + len > n) break;
                auto it1 = mp.find(get(hs, i, i + len - 1));
                auto it2 = mp.find(get(ht, i, i + len - 1));
                if (it1 != mp.end() && it2 != mp.end())
                    dp[i] = min(dp[i], d[it1->second][it2->second] + dp[i + len]);
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};

```