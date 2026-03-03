/*
 Problem: 2665. Minimum Time to Repair Cars
 Language: cpp
 Runtime: 67 ms (25.41%)
 Memory: 59.3 MB (82.14%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e18, res = 0;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (check(ranks, cars, mid)) {
                res = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return res;
    }

private:
    bool check(vector<int>& ranks, int& cars, long long& ti) {
        long long cnt = 0;

        for (const auto& rank: ranks) {
            cnt += (long long) sqrt(ti / rank);
        }

        return cnt >= cars;
    }
};