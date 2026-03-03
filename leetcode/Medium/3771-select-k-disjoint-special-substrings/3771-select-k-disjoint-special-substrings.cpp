/*
 Problem: 3771. Select K Disjoint Special Substrings
 Language: cpp
 Runtime: 8 ms (72.73%)
 Memory: 14.4 MB (62.12%)
 Tags: Hash Table, String, Dynamic Programming, Greedy, Sorting
*/
class Solution {
public:
    bool maxSubstringLength(string s, int k) {
int n = s.size();

        vector<pair<int, int>> pos(26, {n + 1, -1});

        for (int i = 0; i < n; ++i) {
            pos[s[i] - 'a'].first = min(pos[s[i] - 'a'].first, i);
            pos[s[i] - 'a'].second = max(pos[s[i] - 'a'].second, i);
        }

        vector<pair<int, int>> v;

        for (int l = 0; l < n; ++l) {
            if (l != pos[s[l] - 'a'].first) continue;

            int p = l;
            int r = pos[s[l] - 'a'].second;
            bool isOk = true;

            while (p <= r) {
                if (pos[s[p] - 'a'].first < l) {
                    isOk = false;
                    break;
                }

                r = max(r, pos[s[p] - 'a'].second);
                ++p;
            }

            if (isOk && !(l == 0 && r == n - 1)) {
                v.push_back({l, r});
            }
        }

        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });

        int cnt = 0;
        int lastIndex = -1;

        for (const auto& bounds : v)
        {
            if (bounds.first > lastIndex)
            {
                cnt++;
                lastIndex = bounds.second;
            }
        }

        return cnt >= k;
    }
};