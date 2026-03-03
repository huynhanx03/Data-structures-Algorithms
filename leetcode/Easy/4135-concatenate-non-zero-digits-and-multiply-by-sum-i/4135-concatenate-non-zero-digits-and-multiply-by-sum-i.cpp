/*
 Problem: 4135. Concatenate Non-Zero Digits and Multiply by Sum I
 Language: cpp
 Runtime: 4 ms (3.04%)
 Memory: 9.2 MB (30.38%)
 Tags: Math
*/
class Solution {
public:
    long long sumAndMultiply(int n) {
        vector <int> digits;
        while (n > 0) {
            int tmp = n % 10;
            if (tmp > 0) {
                digits.push_back(tmp);
            }
            n /= 10;
        }

        long long ans = 0, sum = 0;
        
        for (int i = digits.size() - 1; i >= 0; --i) {
            sum += digits[i];
            ans = ans * 10 + digits[i];
        }

        return ans * sum;
    }
};