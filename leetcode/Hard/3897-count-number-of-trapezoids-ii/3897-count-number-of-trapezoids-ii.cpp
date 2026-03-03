/*
 Problem: 3897. Count Number of Trapezoids II
 Language: cpp
 Runtime: 1955 ms (40.00%)
 Memory: 555.7 MB (20.00%)
 Tags: Array, Hash Table, Math, Geometry
*/
class Solution {
public:
    int countTrapezoids(const vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, int>> slopeInterceptMap, vectorInterceptMap;

        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = i + 1; j < points.size(); ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                int g = gcd(dx, abs(dy));
                int slopeX = dx / g;
                int slopeY = dy / g;

                int intercept = slopeX * points[i][1] - slopeY * points[i][0];

                int slopeKey = (slopeX << 12) | (slopeY + 2000);
                int vectorKey = (dx << 12) | (dy + 2000);

                slopeInterceptMap[slopeKey][intercept]++;
                vectorInterceptMap[vectorKey][intercept]++;
            }
        }

        return countPairs(slopeInterceptMap) - countPairs(vectorInterceptMap) / 2;
    }

private:
    long long countPairs(const unordered_map<int, unordered_map<int, int>>& map) {
        long long total = 0;
        for (auto& [_, innerMap] : map) {
            long long sum = 0;
            for (auto& [__, count] : innerMap) sum += count;

            for (auto& [__, count] : innerMap) total += count * (sum -= count);
        }
        return total;
    }
};
