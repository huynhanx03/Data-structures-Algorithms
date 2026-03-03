/*
 Problem: 3763. Separate Squares I
 Language: cpp
 Runtime: 104 ms (55.37%)
 Memory: 198.8 MB (45.48%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0.0;
        double low = 1e18, high = -1e18;

        for (auto& s : squares) {
            double y = s[1], l = s[2];
            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = total / 2.0;

        auto areaBelow = [&](double Y) {
            double area = 0.0;
            for (auto& s : squares) {
                double y = s[1], l = s[2];
                if (Y <= y) continue;
                if (Y >= y + l) area += l * l;
                else area += (Y - y) * l;
            }
            return area;
        };

        for (int i = 0; i < 60; ++i) {
            double mid = (low + high) / 2.0;
            if (areaBelow(mid) < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
