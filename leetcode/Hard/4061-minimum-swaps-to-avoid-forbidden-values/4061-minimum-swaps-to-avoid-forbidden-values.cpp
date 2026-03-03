/*
 Problem: 4061. Minimum Swaps to Avoid Forbidden Values
 Language: cpp
 Runtime: 614 ms (13.36%)
 Memory: 318.6 MB (24.69%)
 Tags: Array, Hash Table, Greedy, Counting
*/
class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();

        map <int, int> cnt1, cnt2;

        for (int i = 0; i < n; ++i) {
            ++cnt1[nums[i]];
            ++cnt2[forbidden[i]];
        }

        for (const auto&[v, feq] : cnt1) {
            if (feq + cnt2[v] > n) {
                return -1;
            }
        }

        int bad = 0;
        int feq = 0;

        map <int, int> cnt3;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == forbidden[i]) {
                ++bad;
                ++cnt3[nums[i]];
                feq = max(feq, cnt3[nums[i]]);
            }
        }

        return max(feq, (bad + 1) / 2);
    }
};