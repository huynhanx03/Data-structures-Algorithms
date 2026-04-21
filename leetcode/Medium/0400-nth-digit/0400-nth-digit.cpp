/*
 Problem: 400. Nth Digit
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.9 MB (43.88%)
 Tags: Math, Binary Search
*/
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;

        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }

        long long num = start + (n - 1) / len;
        int idx = (n - 1) % len;

        string s = to_string(num);
        return s[idx] - '0';
    }
};