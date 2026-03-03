/*
 Problem: 507. Perfect Number
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.9 MB (19.69%)
 Tags: Math
*/
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = num == 1 ? 0 : 1;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                int next = num / i;
                sum += i + (i == next ? 0 : next);
            }
        }

        return sum == num;
    }
};