/*
 Problem: 2618. Maximize the Minimum Powered City
 Language: cpp
 Runtime: 95 ms (42.82%)
 Memory: 221.2 MB (50.11%)
 Tags: Array, Binary Search, Greedy, Queue, Sliding Window, Prefix Sum
*/
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int l = max(0, i - r), ri = min(n - 1, i + r);
            pre[l] += stations[i];
            pre[ri + 1] -= stations[i];
        }
        for (int i = 1; i < n; i++)
            pre[i] += pre[i - 1];

        long long left = *min_element(pre.begin(), pre.begin() + n);
        long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;

        auto check = [&](long long target) {
            vector<long long> diff(n + 1, 0);
            long long add = 0, used = 0;
            for (int i = 0; i < n; i++) {
                add += diff[i];
                long long cur = pre[i] + add;
                if (cur < target) {
                    long long need = target - cur;
                    used += need;
                    if (used > k)
                        return false;
                    add += need;
                    if (i + 2 * r + 1 < n)
                        diff[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };

        while (left < right) {
            long long mid = (left + right + 1) / 2;
            if (check(mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};