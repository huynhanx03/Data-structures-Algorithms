/*
 Problem: 3214. Maximize Area of Square Hole in Grid
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 31.9 MB (69.44%)
 Tags: Array, Sorting
*/
class Solution {
public:
    int longestConsecutive(vector<int>& bars) {
        if (bars.empty()) return 0;
        sort(bars.begin(), bars.end());

        int best = 1, cur = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1)
                ++cur;
            else
                cur = 1;
            best = max(best, cur);
        }
        return best;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = longestConsecutive(hBars);
        int maxV = longestConsecutive(vBars);

        int side = min(maxH + 1, maxV + 1);
        return side * side;
    }
};
