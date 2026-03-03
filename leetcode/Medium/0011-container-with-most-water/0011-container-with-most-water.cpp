/*
 Problem: 11. Container With Most Water
 Language: cpp
 Runtime: 50 ms (7.37%)
 Memory: 61.7 MB (99.94%)
 Tags: Array, Two Pointers, Greedy
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;

        while (l <= r) {
            int area = min(height[l], height[r]) * (r - l);

            ans = max(ans, area);

            if (height[l] >= height[r])
                --r;
            else
                ++l;
        }

        return ans;
    }
};