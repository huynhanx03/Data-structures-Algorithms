/*
 Problem: 611. Valid Triangle Number
 Language: cpp
 Runtime: 31 ms (69.12%)
 Memory: 16.8 MB (12.03%)
 Tags: Array, Two Pointers, Binary Search, Greedy, Sorting
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
