/*
 Problem: 4100. Complete Prime Number
 Language: cpp
 Runtime: 4 ms (20.70%)
 Memory: 8.3 MB (62.56%)
 Tags: Math, Enumeration, Number Theory
*/
class Solution {
private:
    bool isPrime (int x) {
        if (x < 2) return 0;
        if (x % 2 == 0) return x == 2;
        for (long long i = 3; i * i <= x; i += 2)
            if (x % i == 0) return 0;

        return 1;
    }
public:
    bool completePrime(int num) {
        vector <int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        int s = 0;
        for (int i = 0; i < digits.size(); ++i) {
            s = s * 10 + digits[i];
            if (!isPrime(s)) return 0;
        }

        s = 0;
        int mul = 1;
        for (int i = digits.size() - 1; i >= 0 ; --i) {
            s = digits[i] * mul + s;
            mul *= 10;
            if (!isPrime(s)) return 0;
        }

        return 1;
    }
};