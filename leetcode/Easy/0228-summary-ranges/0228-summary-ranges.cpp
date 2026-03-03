/*
 Problem: 228. Summary Ranges
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.3 MB (10.19%)
 Tags: Array
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;

        int st = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (static_cast<long>(nums[i]) - static_cast<long>(nums[i - 1]) != 1) {
                if (nums[i - 1] == st) {
                    ans.push_back(to_string(st));
                } else {
                    ans.push_back(to_string(st) + "->" + to_string(nums[i - 1]));
                }
                st = nums[i];
            }
        }

        if (nums.back() == st) {
            ans.push_back(to_string(st));
        } else {
            ans.push_back(to_string(st) + "->" + to_string(nums.back()));
        }

        return ans;
    }
};
