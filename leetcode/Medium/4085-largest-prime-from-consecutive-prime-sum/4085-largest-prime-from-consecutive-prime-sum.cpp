/*
 Problem: 4085. Largest Prime from Consecutive Prime Sum
 Language: cpp
 Runtime: 470 ms (53.49%)
 Memory: 26.4 MB (61.85%)
 Tags: Array, Math, Number Theory
*/
class Solution {
public:
    int largestPrime(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = 0;
        isPrime[1] = 1;

        for (int i = 2; (long long) i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int sum = 0;
        int res = 0;
        
        for (int i = 2; i <= n; ++i) {
            if (!isPrime[i]) continue;

            sum += i;
            if (sum > n) break;

            if (isPrime[sum]) res = sum;
        }
        
        return res;
    }
};