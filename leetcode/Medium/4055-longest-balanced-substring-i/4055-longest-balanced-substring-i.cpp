/*
 Problem: 4055. Longest Balanced Substring I
 Language: cpp
 Runtime: 191 ms (41.66%)
 Memory: 17.3 MB (63.99%)
 Tags: Hash Table, String, Counting, Enumeration
*/
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0;

        vector<pair<int, int>> v;
        v.reserve(n);

        for (int u = 1; u <= 26; ++u) {
            for (int k = 1; k * u <= n; ++k) {
                v.push_back({k * u, u});
            }
        }

        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        int ans = 0;
        for (const auto& p : v) {
            int len = p.first;
            int u = p.second;

            if (len <= ans) break;

            int target = len / u;
            int cnt[26] = {0};
            int distinct = 0;
            int match = 0;

            for (int i = 0; i < len; ++i) {
                int idx = s[i] - 'a';
                if (cnt[idx] == 0) ++distinct;
                ++cnt[idx];
                if (cnt[idx] == target) ++match;
                else if (cnt[idx] == target + 1) --match;
            }

            if (distinct == u && match == u) {
                ans = max(ans, len);
                continue;
            }

            for (int i = len; i < n; ++i) {
                int in = s[i] - 'a';
                int out = s[i - len] - 'a';

                if (cnt[in] == 0) ++distinct;
                ++cnt[in];
                if (cnt[in] == target) ++match;
                else if (cnt[in] == target + 1) --match;

                if (cnt[out] == target) --match;
                else if (cnt[out] == target + 1) ++match;
                --cnt[out];
                if (cnt[out] == 0) --distinct;

                if (distinct == u && match == u) {
                    ans = max(ans, len);
                    break; 
                }
            }
        }

        return ans;
    }
};