/*
 Problem: 3724. Filter Occupied Intervals
 Language: cpp
 Runtime: 89 ms (79.48%)
 Memory: 192.5 MB (69.40%)
 Tags: Array, Sorting
*/
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        for (const auto& interval : occupiedIntervals) {
            int start = interval[0];
            int end = interval[1];

            if (merged.empty() || start > merged.back()[1] + 1) {
                merged.push_back({start, end});
            } else {
                merged.back()[1] = max(merged.back()[1], end);
            }
        }

        vector<vector<int>> ans;

        for (const auto& interval : merged) {
            int start = interval[0];
            int end = interval[1];

            if (end < freeStart || start > freeEnd) {
                ans.push_back({start, end});
                continue;
            }

            if (start < freeStart) {
                ans.push_back({start, freeStart - 1});
            }

            if (end > freeEnd) {
                ans.push_back({freeEnd + 1, end});
            }
        }

        return ans;
    }
};