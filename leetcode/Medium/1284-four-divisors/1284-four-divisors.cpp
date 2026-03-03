/*
 Problem: 1284. Four Divisors
 Language: cpp
 Runtime: 8 ms (72.00%)
 Memory: 16.3 MB (51.78%)
 Tags: Array, Math
*/
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (auto n : nums) {
            int sum = 1 + n;
            int cnt = 2;

            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    int j = n / i;
                    if (i == j) {
                        cnt += 1;
                        sum += i;
                    } else {
                        cnt += 2;
                        sum += i + j;
                    }
                }
                if (cnt > 4) break;
            }

            if (cnt == 4) {
                result += sum;
            }
        }

        return result;
    }
};
