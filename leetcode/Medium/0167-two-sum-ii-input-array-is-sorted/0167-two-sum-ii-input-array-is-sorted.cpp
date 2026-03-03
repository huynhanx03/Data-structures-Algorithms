/*
 Problem: 167. Two Sum II - Input Array Is Sorted
 Language: cpp
 Runtime: 7 ms (1.99%)
 Memory: 18.3 MB (100.00%)
 Tags: Array, Two Pointers, Binary Search
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];

            if (sum == target) {
                return vector<int> {l + 1, r + 1};
            } else if (sum > target)
                --r;
            else
                ++l;
        }

        return vector<int>();
    }
};