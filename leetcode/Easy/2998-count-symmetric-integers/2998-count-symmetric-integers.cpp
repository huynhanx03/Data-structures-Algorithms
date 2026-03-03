/*
 Problem: 2998.   Count Symmetric Integers
 Language: cpp
 Runtime: 603 ms (5.08%)
 Memory: 146.2 MB (5.23%)
 Tags: Math, Enumeration
*/
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for (int v = low; v <= high; ++v) {
            vector<int> digits;

            int x = v;

            while (x > 0) {
                digits.push_back(x % 10);
                x /= 10;
            }

            int n = digits.size();
            if (n&1) continue;

            int sumLeft = 0, sumRight = 0;

            for (int i = 0; i < n / 2; ++i)
                sumLeft += digits[i];

            for (int i = (n + 1) / 2; i < n; ++i)
                sumRight += digits[i];
            
            if (sumLeft == sumRight) {
                ++cnt;
                // cout << v << '\n';
            }
        }

        return cnt;
    }
};