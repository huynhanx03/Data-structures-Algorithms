/*
 Problem: 283. Move Zeroes
 Language: cpp
 Runtime: 14 ms (7.80%)
 Memory: 23.1 MB (99.99%)
 Tags: Array, Two Pointers
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        vector<int> ans;

        for (auto& num : nums) {
            if (num == 0)
                ++cnt;
            else
                ans.push_back(num);
        }

        while(cnt--)
            ans.push_back(0);

        nums = ans;
    }
};