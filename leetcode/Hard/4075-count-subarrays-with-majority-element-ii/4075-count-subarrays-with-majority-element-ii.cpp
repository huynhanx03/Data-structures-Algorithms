/*
 Problem: 4075. Count Subarrays With Majority Element II
 Language: cpp
 Runtime: 29 ms (41.57%)
 Memory: 95.8 MB (53.98%)
 Tags: Array, Hash Table, Divide and Conquer, Segment Tree, Merge Sort, Prefix Sum
*/
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 2;
        int size = 2 * n + 5;

        vector<int> bit(size + 1, 0);

        auto add = [&](int idx) {
            while (idx <= size) {
                ++bit[idx];
                idx += idx & -idx;
            }
        };

        auto sum = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };

        long long ans = 0;
        int prefix = 0;

        add(prefix + offset);

        for (const auto& x : nums) {
            if (x == target) ++prefix;
            else --prefix;

            int idx = prefix + offset;

            ans += sum(idx - 1);
            add(idx);
        }

        return ans;
    }
};