/*
 Problem: 1335. Maximum Candies Allocated to K Children
 Language: cpp
 Runtime: 45 ms (11.56%)
 Memory: 88.1 MB (95.30%)
 Tags: Array, Binary Search
*/
class Solution {
private:
    long long count(vector<int>& candies, int& v) {
        long long cnt = 0;

        for (const auto& x: candies) {
            cnt += x / v;
        }

        return cnt;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = 1e9, res = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (count(candies, mid) >= k) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};