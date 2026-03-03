/*
 Problem: 3643. Zero Array Transformation II
 Language: cpp
 Runtime: 75 ms (42.64%)
 Memory: 369.6 MB (16.28%)
 Tags: Array, Binary Search, Prefix Sum
*/
class Solution {
private:
    bool isZeroArrayPossible(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(nums.size() + 1, 0);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < diff.size())
                diff[r + 1] += val;
        }

        int currentValue = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentValue += diff[i];
            nums[i] += currentValue;
            if (nums[i] > 0)
                return false;
        }

        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (nums.empty()) return 0;

        int left = 0, right = queries.size(), result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            vector<int> tempNums = nums;

            if (isZeroArrayPossible(tempNums, queries, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
