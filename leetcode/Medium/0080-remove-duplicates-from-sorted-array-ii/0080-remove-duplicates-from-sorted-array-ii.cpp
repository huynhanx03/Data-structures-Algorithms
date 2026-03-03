/*
 Problem: 80. Remove Duplicates from Sorted Array II
 Language: cpp
 Runtime: 4 ms (83.68%)
 Memory: 13.7 MB (100.00%)
 Tags: Array, Two Pointers
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int k = 0;
        int n = nums.size();

        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                ++cnt;
            } else {
                cnt = min(cnt, 2);

                while (cnt > 0) {
                    nums[k] = nums[i - 1];
                    ++k;
                    --cnt;
                }

                cnt = 1;
            }
        }

        cnt = min(cnt, 2);

        while (cnt > 0) {
            nums[k] = nums[n - 1];
            ++k;
            --cnt;
        }

        return k;
    }
};