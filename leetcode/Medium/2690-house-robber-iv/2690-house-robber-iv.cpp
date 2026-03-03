/*
 Problem: 2690. House Robber IV
 Language: cpp
 Runtime: 31 ms (17.75%)
 Memory: 60.8 MB (95.56%)
 Tags: Array, Binary Search, Dynamic Programming, Greedy
*/
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 1e9, res = 1e9;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(nums, n, k, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }

private:
    bool check(vector<int>& nums, int& n, int& k, int& v) {
        int i = 0, cnt = 0;

        while (i < n) {
            if (nums[i] <= v) {
                ++cnt;
                i += 2;
            } else
                ++i;
        }

        return cnt >= k;
    }
};