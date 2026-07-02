/*
 Problem: 4300. Minimum Operations to Make Array Modulo Alternating I
 Language: cpp
 Runtime: 95 ms (59.60%)
 Memory: 23.8 MB (93.71%)
 Tags: Array, Enumeration
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        auto get = [&](int a, int b) {
            int d = abs(a - b);
            return min(d, k - d);
        };

        int ans = INT_MAX;

        for (int x = 0; x < k; ++x) {
            for (int y = 0; y < k; ++y) {
                if (x == y) continue;

                int cost = 0;

                for (int i = 0; i < n; ++i) {
                    int tmp = nums[i] % k;

                    if (i % 2 == 0) {
                        cost += get(tmp, x);
                    } else {
                        cost += get(tmp, y);
                    }
                }

                ans = min(cost, ans);
            }
        }
        
        return ans;
    }
};