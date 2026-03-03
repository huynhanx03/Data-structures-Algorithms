/*
 Problem: 2263. Maximum Running Time of N Computers
 Language: cpp
 Runtime: 26 ms (44.20%)
 Memory: 59.8 MB (23.55%)
 Tags: Array, Binary Search, Greedy, Sorting
*/
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (long long b : batteries) total += b;

        long long left = 0;
        long long right = total / n;

        auto canRun = [&](long long& x) {
            long long sum = 0;
            for (const long long& b : batteries) {
                sum += min(b, x);
            }
            return sum >= x * n;
        };

        while (left < right) {
            long long mid = (left + right + 1) / 2;
            if (canRun(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};
