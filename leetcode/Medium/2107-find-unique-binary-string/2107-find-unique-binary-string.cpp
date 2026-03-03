/*
 Problem: 2107. Find Unique Binary String
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 12.6 MB (86.04%)
 Tags: Array, Hash Table, String, Backtracking
*/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";

        for (int i = 0; i < nums.size(); ++i) {
            res = res + (nums[i][i] == '1' ? '0' : '1');
        }

        return res;
    }
};