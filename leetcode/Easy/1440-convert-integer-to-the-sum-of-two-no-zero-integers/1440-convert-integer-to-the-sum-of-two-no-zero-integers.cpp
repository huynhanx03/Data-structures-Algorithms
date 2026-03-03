/*
 Problem: 1440. Convert Integer to the Sum of Two No-Zero Integers
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.2 MB (59.82%)
 Tags: Math
*/
class Solution {
public:
    bool isNoZero(int x) {
        while (x > 0) {
            if (x % 10 == 0)
                return false;
            x /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isNoZero(a) && isNoZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};