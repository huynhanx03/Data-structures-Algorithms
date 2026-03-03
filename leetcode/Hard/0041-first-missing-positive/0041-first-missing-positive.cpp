/*
 Problem: 41. First Missing Positive
 Language: cpp
 Runtime: 4 ms (42.91%)
 Memory: 55.1 MB (62.65%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // loại <= 0, > n
        for (auto&num: nums) {
            if (num <= 0 || num > n) num = n + 1;
        }

        // gán giá trị âm để
        // giá trị âm thì i tại đó không nhận
        for (const auto&num: nums) {
            int v = abs(num);

            if (v <= n) {
                // đảm bảo luôn âm khi đã có value v
                nums[v - 1] = -abs(nums[v - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};