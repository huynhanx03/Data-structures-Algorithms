/*
 Problem: 3332. Minimum Operations to Exceed Threshold Value II
 Language: cpp
 Runtime: 92 ms (79.37%)
 Memory: 99.2 MB (24.80%)
 Tags: Array, Heap (Priority Queue), Simulation
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;

        for (const auto&num: nums) {
            pq.push(num);
        }

        int cnt = 0;

        while (pq.size() > 1 && pq.top() < k) {
            int num1 = pq.top();
            pq.pop();

            int num2 = pq.top();
            pq.pop();

            pq.push((long) min(num1, num2) * 2 + max(num1, num2));
            
            ++cnt;
        }

        return cnt;
    }
};