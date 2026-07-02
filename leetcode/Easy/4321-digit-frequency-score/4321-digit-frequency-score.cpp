/*
 Problem: 4321. Digit Frequency Score
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.6 MB (64.42%)
 Tags: Hash Table, Math
*/
class Solution {
public:
    int digitFrequencyScore(int n) {
        vector <int> cnt(10, 0);

        while (n > 0) {
            ++cnt[n % 10];
            n /= 10;
        }
        
        int s = 0;

        for (int i = 1; i <= 9; ++i) s += cnt[i] * i;
        
        return s;
    }
};