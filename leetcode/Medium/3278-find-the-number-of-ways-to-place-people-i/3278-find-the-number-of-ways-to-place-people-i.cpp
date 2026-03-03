/*
 Problem: 3278. Find the Number of Ways to Place People I
 Language: cpp
 Runtime: 4 ms (61.47%)
 Memory: 32.7 MB (39.42%)
 Tags: Array, Math, Geometry, Sorting, Enumeration
*/
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });

        int n = points.size();
        int result = 0;

        for (int i = 0; i < n - 1; i++) {
            int minY = INT_MAX;
            int yA = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int yB = points[j][1];
                if (yB >= yA && yB < minY) {
                    result++;
                    minY = yB;
                }
            }
        }
        return result;
    }
};
