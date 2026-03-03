/*
 Problem: 3277. Find the Number of Ways to Place People II
 Language: cpp
 Runtime: 103 ms (78.33%)
 Memory: 41.2 MB (92.57%)
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
