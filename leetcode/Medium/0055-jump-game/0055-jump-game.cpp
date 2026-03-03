/*
 Problem: 55. Jump Game
 Language: cpp
 Runtime: 43 ms (17.38%)
 Memory: 51.1 MB (99.93%)
 Tags: Array, Dynamic Programming, Greedy
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 0;

        for (auto num : nums) {
            if (step < 0)
                return 0;
            
            if (num > step)
                step = num;

            --step;
        }

        return true;
    }
};