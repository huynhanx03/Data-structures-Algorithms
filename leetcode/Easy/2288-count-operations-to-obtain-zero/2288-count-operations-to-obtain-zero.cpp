/*
 Problem: 2288. Count Operations to Obtain Zero
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.8 MB (97.56%)
 Tags: Math, Simulation
*/
class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2) {
                count += num1 / num2;
                num1 %= num2;
            } else {
                count += num2 / num1;
                num2 %= num1;
            }
        }
        return count;
    }
};