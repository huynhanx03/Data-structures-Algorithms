/*
 Problem: 1889. Check if Number is a Sum of Powers of Three
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.8 MB (62.06%)
 Tags: Math
*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2)
                return false;

            n /= 3;
        }
    
        return true;
    }
};