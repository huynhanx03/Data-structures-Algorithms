/*
 Problem: 1548. Check If All 1's Are at Least Length K Places Away
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 61.4 MB (91.44%)
 Tags: Array
*/
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                if (pre != -1) {
                    if (i - pre - 1 < k)
                        return false;
                }

                pre = i;
            }
        }

        return true;
    }
};