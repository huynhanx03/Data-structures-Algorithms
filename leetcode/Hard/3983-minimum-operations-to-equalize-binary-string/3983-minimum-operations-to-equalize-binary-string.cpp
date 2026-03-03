/*
 Problem: 3983. Minimum Operations to Equalize Binary String
 Language: cpp
 Runtime: 3 ms (81.17%)
 Memory: 19.1 MB (66.94%)
 Tags: Math, String, Breadth-First Search, Union-Find, Ordered Set
*/
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        
        int z = 0;
        for (const auto& c : s) {
            z += ~c & 1;
        }

        if (!z) {
            return 0;
        }

        if (k == n) {
            return ((z == n) << 1) - 1;
        }

        int base = n - k;

        int odd = max(
            (z + k - 1) / k,
            (n - z + base - 1) / base
        );
        odd += ~odd & 1;

        int even = max(
            (z + k - 1) / k,
            (z + base - 1) / base
        );
        even += even & 1;

        int ans = INT_MAX;

        if ((k & 1) == (z & 1)) {
            ans = min(ans, odd);
        }

        if (~z & 1) {
            ans = min(ans, even);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};