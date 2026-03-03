/*
 Problem: 414. Third Maximum Number
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 13.1 MB (31.53%)
 Tags: Array, Sorting
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int num : nums) {
            if (num == first || num == second || num == third) {
                continue;
            }

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        return (third == LONG_MIN) ? first : third;
    }
};