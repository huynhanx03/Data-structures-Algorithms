/*
 Problem: 958. Sort Array By Parity II
 Language: cpp
 Runtime: 21 ms (4.00%)
 Memory: 25 MB (99.95%)
 Tags: Array, Two Pointers, Sorting
*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> op, ep;
        
        for (int i = 0; i < nums.size(); ++i) {
            if ((i + nums[i]) % 2 != 0) {
                if (i % 2 == 0) 
                    ep.push_back(i);
                else
                    op.push_back(i);
            }
        }
        
        for (int i = 0; i < op.size(); ++i) {
            // int tmp = nums[ep[i]];
            // nums[ep[i]] = nums[op[i]];
            // nums[op[i]] = tmp;
            swap(nums[ep[i]], nums[op[i]]);
        }
        
        return nums;
    }
};