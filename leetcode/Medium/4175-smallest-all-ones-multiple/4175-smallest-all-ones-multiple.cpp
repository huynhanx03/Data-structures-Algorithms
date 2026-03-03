/*
 Problem: 4175. Smallest All-Ones Multiple
 Language: cpp
 Runtime: 7 ms (85.67%)
 Memory: 8.5 MB (87.09%)
 Tags: Hash Table, Math
*/
class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int rem = 0;
        for (int l = 1; l <= k; ++l) {
            rem = (rem * 10 + 1) % k;

            if (rem == 0) return l;
        }

        return -1;
    }
};