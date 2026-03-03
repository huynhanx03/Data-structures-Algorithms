/*
 Problem: 42. Trapping Rain Water
 Language: cpp
 Runtime: 7 ms (5.54%)
 Memory: 23.3 MB (100.00%)
 Tags: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> maxLeft(n + 2, 0);
        vector<int> maxRight(n + 2, 0);

        for (int i = 0; i < n; ++i) {
            maxLeft[i + 1] = max(maxLeft[i], height[i]);
        }

        
        for (int i = n - 1; i >= 0; --i) {
            maxRight[i + 1] = max(maxRight[i + 2], height[i]);
        }

        int result = 0;

        for (int i = 1; i <= n; ++i) {
            result += min(maxRight[i], maxLeft[i]) - height[i - 1];
        }

        return result;
    }
};