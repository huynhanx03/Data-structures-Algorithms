/*
 Problem: 4090. Minimum String Length After Balanced Removals
 Language: cpp
 Runtime: 1 ms (74.56%)
 Memory: 15.1 MB (33.77%)
 Tags: String, Stack, Counting
*/
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        vector<int>cnt(2, 0);
        int n = s.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];

            if (cnt[0] != 0 && cnt[1] != 0) {
                int diff = min(cnt[0], cnt[1]);
                ans -= diff * 2;
                cnt[0] -= diff;
                cnt[1] -= diff;
            }
        }

        return ans;
    }
};