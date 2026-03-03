/*
 Problem: 2610. Closest Prime Numbers in Range
 Language: cpp
 Runtime: 1123 ms (5.10%)
 Memory: 17.4 MB (57.39%)
 Tags: Math, Number Theory
*/
class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }

        int minDiff = numeric_limits<int>::max();
        vector<int> result = {-1, -1};
        for (size_t i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i], primes[i + 1]};
            }
        }

        return result;
    }
};