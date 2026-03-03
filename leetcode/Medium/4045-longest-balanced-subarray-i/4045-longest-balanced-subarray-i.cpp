/*
 Problem: 4045. Longest Balanced Subarray I
 Language: cpp
 Runtime: 2001 ms (27.94%)
 Memory: 530.5 MB (9.87%)
 Tags: Array, Hash Table, Divide and Conquer, Segment Tree, Prefix Sum
*/
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; ++l) {
            unordered_set<int> even, odd;
            int ce = 0, co = 0;

            for (int r = l; r < n; ++r) {
                int x = nums[r];
                if (x % 2 == 0) {
                    if (!even.count(x)) {
                        even.insert(x);
                        ++ce;
                    }
                } else {
                    if (!odd.count(x)) {
                        odd.insert(x);
                        ++co;
                    }
                }

                if (ce == co)
                    ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};