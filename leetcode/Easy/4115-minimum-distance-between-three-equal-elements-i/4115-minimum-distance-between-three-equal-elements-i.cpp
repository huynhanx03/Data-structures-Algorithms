/*
 Problem: 4115. Minimum Distance Between Three Equal Elements I
 Language: cpp
 Runtime: 3 ms (71.67%)
 Memory: 28.7 MB (81.33%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int z = j + 1; z < n; ++z) {
                    if (nums[i] == nums[j] && nums[j] == nums[z])
                        ans = min(ans, abs(i - j) + abs(i - z) + abs(j - z));
                }
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};