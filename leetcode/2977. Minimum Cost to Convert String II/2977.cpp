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
