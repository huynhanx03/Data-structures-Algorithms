/*
 Problem: 2037. Count Square Sum Triples
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.7 MB (85.60%)
 Tags: Math, Enumeration
*/
class Solution {
public:
    int countTriples(int N) {
        int count = 0;

        for (int m = 2; 1ll * m * m <= N; m++) {
            for (int n = 1; n < m; n++) {
                if (((m - n) & 1) == 0) continue;
                if (gcd(m, n) != 1) continue;

                int a = m*m - n*n;
                int b = 2*m*n;
                int c = m*m + n*n;

                if (c > N) break;

                for (int k = 1; k * c <= N; k++) {
                    int A = a * k;
                    int B = b * k;
                    if (A <= N && B <= N) count += 2;
                }
            }
        }

        return count;
    }
};
