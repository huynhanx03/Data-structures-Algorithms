/*
 Problem: 2689. Rearranging Fruits
 Language: cpp
 Runtime: 278 ms (5.34%)
 Memory: 131.3 MB (5.34%)
 Tags: Array, Hash Table, Greedy, Sort
*/
class Solution {
public:
    long long minCost(vector<int>& arrA, vector<int>& arrB) {
        map<int, int> cnt;
        multiset<long long> sa, sb;

        long long mindone = 1e9;

        for (const auto& a : arrA) {
            ++cnt[a];
            sa.insert(a);
        }

        for (const auto& b : arrB) {
            --cnt[b];

            if (sa.find(b) != sa.end()) {
                sa.erase(sa.find(b));
                mindone = min(mindone, (long long)b);
            } else {
                sb.insert(b);
            }
        }

        for (const auto& [x, y] : cnt) {
            int v = abs(y);

            if (v % 2 == 1)
                return -1;
        }

        long long ans = 0;
        
        while (sa.size() != 0) {
            if (mindone * 2 <= min(*sa.begin(), *sb.begin())) {
                ans += mindone * sa.size();
                break;
            }

            if (*sa.begin() < *sb.begin()) {
                ans += *sa.begin();
                mindone = min(*sa.begin(), mindone);
                sa.erase(sa.begin());
                sa.erase(sa.begin());
                sb.erase(--sb.end());
                sb.erase(--sb.end());
            } else {
                ans += *sb.begin();
                mindone = min(*sb.begin(), mindone);
                sb.erase(sb.begin());
                sb.erase(sb.begin());
                sa.erase(--sa.end());
                sa.erase(--sa.end());
            }
        }

        return ans;
    }
};