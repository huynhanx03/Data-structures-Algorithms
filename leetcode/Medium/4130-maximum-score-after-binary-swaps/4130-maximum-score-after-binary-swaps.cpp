/*
 Problem: 4130. Maximum Score After Binary Swaps
 Language: cpp
 Runtime: 51 ms (60.32%)
 Memory: 127.4 MB (73.81%)
 Tags: Array, String, Greedy, Heap (Priority Queue)
*/
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long res = 0;

        priority_queue <int> pq;

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            pq.push(nums[i]);

            if (s[i] == '1') {
                res += pq.top();
                pq.pop();
            }
        }
        
        return res;
    }
};