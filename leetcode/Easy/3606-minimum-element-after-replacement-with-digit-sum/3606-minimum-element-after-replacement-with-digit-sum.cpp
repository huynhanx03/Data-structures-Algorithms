/*
 Problem: 3606. Minimum Element After Replacement With Digit Sum
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 27.7 MB (73.81%)
 Tags: Array, Math
*/
class Solution {
public:
    int minElement(vector<int>& nums) {
        auto get = [&](int x) {
            int s = 0;

            while (x > 0) {
                s += x % 10;
                x /= 10;
            }

            return s;
        };

        int ans = 1e9;

        for (const auto& x : nums) ans = min(ans, get(x));

        return ans;
    }
};