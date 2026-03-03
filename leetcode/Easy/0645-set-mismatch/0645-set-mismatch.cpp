/*
 Problem: 645. Set Mismatch
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 25.6 MB (59.67%)
 Tags: Array, Hash Table, Bit Manipulation, Sorting
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> check(nums.size() + 1, 0);
        int dup = -1, v = -1;

        for (const auto& x : nums) {
            if (check[x]) {
                dup = x;
            }

            check[x] = 1;
        }

        for (int i = 1; i <= nums.size(); ++i) {
            if (check[i]) continue;
            v = i;
            break;
        }

        return {dup, v};
    }
};