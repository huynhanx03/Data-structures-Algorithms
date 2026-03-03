/*
 Problem: 2164. Two Best Non-Overlapping Events
 Language: cpp
 Runtime: 52 ms (96.50%)
 Memory: 158.4 MB (97.70%)
 Tags: Array, Binary Search, Dynamic Programming, Sorting, Heap (Priority Queue)
*/
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int end = events[i][1];
            int value = events[i][2];

            ans = max(ans, value);

            int left = i + 1, right = n - 1;
            int idx = -1;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (events[mid][0] >= end + 1) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (idx != -1) {
                ans = max(ans, value + suffixMax[idx]);
            }
        }

        return ans;
    }
};
