/*
 Problem: 50. Pow(x, n)
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.4 MB (99.72%)
 Tags: Math, Recursion
*/
class Solution {
public:
    double myPow(double x, int n) {
        long num = labs(n);

        if (n < 0)
            x = 1 / x;

        double pow = 1;

        while (num) {      // equivalent to while(num != 0)
            if (num & 1) // equivalent to if((num & 1) != 0)
                pow *= x;

            x *= x;
            num >>= 1;
        }

        return pow;
    }
};