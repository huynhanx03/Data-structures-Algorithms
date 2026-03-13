/*
 Problem: 3496. Minimum Number of Seconds to Make Mountain Height Zero
 Language: cpp
 Runtime: 15 ms (74.84%)
 Memory: 29 MB (43.87%)
 Tags: Array, Math, Binary Search, Greedy, Heap (Priority Queue)
*/
class Solution {
public:
    bool canFinish(long long& T, int& mountainHeight, const vector<int>& workerTimes) {
        long long total = 0;

        for (const auto& t : workerTimes) {
            long long val = (2LL * T) / t;

            long long x = ((long long) sqrt(1 + 4 * val) - 1) >> 1;

            total += x;

            if (total >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = 1e18;

        while (left < right) {
            long long mid = left + ((right - left) >> 1);

            if (canFinish(mid, mountainHeight, workerTimes))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};