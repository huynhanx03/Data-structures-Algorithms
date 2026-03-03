/*
 Problem: 278. First Bad Version
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.9 MB (41.23%)
 Tags: Binary Search, Interactive
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;

        int res = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isBadVersion(mid)) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return res;
    }
};