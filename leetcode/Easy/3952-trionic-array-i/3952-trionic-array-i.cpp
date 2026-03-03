/*
 Problem: 3952. Trionic Array I
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 27.7 MB (72.74%)
 Tags: Array
*/
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 1;

        while (i < n && nums[i] > nums[i - 1]) ++i;
        if (i == 1 || i == n) return false;

        while (i < n && nums[i] < nums[i - 1]) ++i;
        if (i == n) return false;

        while (i < n && nums[i] > nums[i - 1]) ++i;

        return i == n;
    }
};
