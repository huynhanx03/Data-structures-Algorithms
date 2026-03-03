/*
 Problem: 3427. Special Array II
 Language: cpp
 Runtime: 39 ms (34.11%)
 Memory: 136.4 MB (18.06%)
 Tags: Array, Binary Search, Prefix Sum
*/
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<bool> check(n, 0);
        vector<int> ps(n, 0);
        vector<bool> result;

        for (int i = 1; i < n; ++i) {
            check[i] = (a[i] + a[i - 1]) % 2 != 0;
        }

        for (int i = 1; i < n; ++i) {
            ps[i] = ps[i - 1] + check[i];
        }

        for (const auto query : queries) {
            int f = query[0];
            int s = query[1];

            if (f == s) {
                result.push_back(true);
                continue;
            }

            int value = ps[s] - ps[f];

            result.push_back(value == (s - f));
        }

        return result;
    }
};