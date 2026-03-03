/*
 Problem: 2473. Max Sum of a Pair With Equal Sum of Digits
 Language: cpp
 Runtime: 77 ms (12.97%)
 Memory: 75 MB (37.18%)
 Tags: Array, Hash Table, Sorting, Heap (Priority Queue)
*/
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> digitSumMap;
        
        for (int num : nums) {
            int sum = digitSum(num);
            digitSumMap[sum].push_back(num);
        }
        
        int maxSum = -1;
        for (auto& [sum, group] : digitSumMap) {
            if (group.size() > 1) {
                sort(group.rbegin(), group.rend());
                maxSum = max(maxSum, group[0] + group[1]);
            }
        }
        
        return maxSum;
    }

private:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};