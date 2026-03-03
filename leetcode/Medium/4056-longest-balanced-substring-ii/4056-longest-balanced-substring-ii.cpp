/*
 Problem: 4056. Longest Balanced Substring II
 Language: cpp
 Runtime: 279 ms (97.82%)
 Memory: 135.2 MB (88.65%)
 Tags: Hash Table, String, Prefix Sum
*/
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0, k = 0; i < n; ++i) {
            k = (i > 0 && s[i] == s[i - 1]) ? k + 1 : 1;
            ans = max(ans, k);
        }

        auto check = [&](char a, char b, char x) {
            vector<int> seen(2 * n + 1, -2);
            vector<int> hist;
            int bal = 0;
            seen[n] = -1;
            hist.push_back(n);

            for (int i = 0; i < n; ++i) {
                if (s[i] == x) {
                    for (int idx : hist) seen[idx] = -2;
                    hist.clear();
                    bal = 0;
                    seen[n] = i;
                    hist.push_back(n);
                } else {
                    bal += (s[i] == a ? 1 : -1);
                    if (seen[bal + n] != -2) ans = max(ans, i - seen[bal + n]);
                    else {
                        seen[bal + n] = i;
                        hist.push_back(bal + n);
                    }
                }
            }
        };

        check('a', 'b', 'c');
        check('a', 'c', 'b');
        check('b', 'c', 'a');

        unordered_map<long long, int> mp;
        vector<int> cnt(3, 0);
        auto getKey = [](int x, int y) {
            return ((long long)x << 32) | (unsigned int)y;
        };

        mp[getKey(0, 0)] = -1;

        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
            long long key = getKey(cnt[0] - cnt[1], cnt[1] - cnt[2]);
            if (auto it = mp.find(key); it != mp.end()) {
                ans = max(ans, i - it->second);
            } else {
                mp[key] = i;
            }
        }

        return ans;
    }
};