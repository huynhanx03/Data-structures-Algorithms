/*
 Problem: 3299. Find the Maximum Number of Elements in Subset
 Language: cpp
 Runtime: 74 ms (63.42%)
 Memory: 122.8 MB (27.45%)
 Tags: Array, Hash Table, Enumeration
*/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (const auto& x : nums) ++freq[x];

        int ans = 1;

        if (freq.count(1)) {
            int cnt = freq[1];
            if (cnt % 2 == 0) --cnt;
            ans = max(ans, cnt);
        }

        for (auto &[num, cnt] : freq) {
            if (num == 1)
                continue;

            long long cur = num;
            int len = 0;

            while (freq.count(cur)) {
                if (freq[cur] >= 2) {
                    len += 2;
                } else {
                    ++len;
                    break;
                }

                if (cur > 1000000000LL / cur)
                    break;

                cur *= cur;
            }

            if (len % 2 == 0) --len;

            ans = max(ans, len);
        }

        return ans;
    }
};