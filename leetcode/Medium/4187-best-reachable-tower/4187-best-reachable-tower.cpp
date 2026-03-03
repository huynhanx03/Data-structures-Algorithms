/*
 Problem: 4187. Best Reachable Tower
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 274.9 MB (78.34%)
 Tags: Array
*/
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector <int> res = {-1, -1};
        int max_quality = -1;

        int cx = center[0], cy = center[1];

        for (const auto&t : towers) {
            int tx = t[0], ty = t[1], tq = t[2];
            int dist = abs(tx - cx) + abs(ty - cy);

            if (dist <= radius) {
                if (tq > max_quality) {
                    max_quality = tq;
                    res = {tx, ty};
                } else if (tq == max_quality) {
                    if (tx < res[0]) {
                        res = {tx, ty};
                    } else if (tx == res[0] && ty < res[1]) {
                        res = {tx, ty};
                    }
                }
            }
        }

        return res;
    }
};