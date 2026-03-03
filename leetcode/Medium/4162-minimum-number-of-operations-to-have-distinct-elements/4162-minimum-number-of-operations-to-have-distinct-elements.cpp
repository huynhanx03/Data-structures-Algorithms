/*
 Problem: 4162. Minimum Number of Operations to Have Distinct Elements
 Language: cpp
 Runtime: 96 ms (58.99%)
 Memory: 187.4 MB (62.93%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map <int, bool> check;
        int n = nums.size();
        int pos = n;

        for (int i = n - 1; i >= 0; --i) {
            if (check[nums[i]]) break;

            check[nums[i]] = true;

            pos = i;
        }

        return (pos + 2) / 3;
    }
};