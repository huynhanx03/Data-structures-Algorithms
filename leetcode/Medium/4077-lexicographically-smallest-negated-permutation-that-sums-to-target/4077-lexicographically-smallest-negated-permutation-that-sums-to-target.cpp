/*
 Problem: 4077. Lexicographically Smallest Negated Permutation that Sums to Target
 Language: cpp
 Runtime: 423 ms (5.09%)
 Memory: 139.1 MB (5.28%)
 Tags: Array, Math, Two Pointers, Greedy, Sorting
*/
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long S = 1LL * n * (n + 1) / 2;
        long long diff = S - target;

        if (diff < 0 || diff % 2 != 0)
            return {};

        long long need = diff / 2;
        vector<int> vneeds;
        for (int x = n; x >= 1; --x) {
            if (need >= x) {
                vneeds.push_back(x);
                need -= x;
            }
        }

        if (need != 0) {
            return {};
        }

        vector <int> ans(n);

        set<int> st(vneeds.begin(), vneeds.end());

        int sz = 0;
        
        for (int i = n; i >= 1; --i) {
            if (st.count(i)) {
                ans[sz++] = -i;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (!st.count(i)) {
                ans[sz++] = i;
            }
        }

        return ans;
    }
};