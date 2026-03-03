/*
 Problem: 2661. Smallest Missing Non-negative Integer After Operations
 Language: cpp
 Runtime: 179 ms (12.68%)
 Memory: 137.3 MB (39.71%)
 Tags: Array, Hash Table, Math, Greedy
*/
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map <int, int> cnt;

        for (const auto& x: nums) {
            ++cnt[((x % value) + value) % value];
        }

        for (int i = 0; i <= 1e5 + 5; ++i) {
            int x = i % value;
            if (cnt[x] == 0)
                return i;

            --cnt[x];
        }

        return -1;
    }
};