/*
 Problem: 954. Maximum Sum Circular Subarray
 Language: cpp
 Runtime: 52 ms (5.09%)
 Memory: 42.5 MB (100.00%)
 Tags: Array, Divide and Conquer, Dynamic Programming, Queue, Monotonic Queue
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // total sum - min(subarray)

        int sumMax = 0, sumMin = 0;
        int total = 0;
        int ansMax = -1e9, ansMin = 1e9;
        int maxValue = -1e9;

        for (auto num : nums) {
            total += num;
            maxValue = max(maxValue, num);

            sumMax += num;
            sumMin += num;

            ansMax = max(ansMax, max(sumMax, num));
            ansMin = min(ansMin, min(sumMin, num));

            if (sumMin > 0)
                sumMin = 0;
            
            if (sumMax < 0)
                sumMax = 0;
        }

        ansMin = min(ansMin, 0);
        ansMax = max(ansMax, maxValue);

        int x = total == ansMin ? -1e9 : total - ansMin;

        return max(x, ansMax);
    }
};