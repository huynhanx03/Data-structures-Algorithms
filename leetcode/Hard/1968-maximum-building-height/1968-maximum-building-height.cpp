/*
 Problem: 1968. Maximum Building Height
 Language: cpp
 Runtime: 91 ms (46.79%)
 Memory: 106.5 MB (95.24%)
 Tags: Array, Math, Sorting
*/
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for (int i = 1; i < m; i++)
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]
            );

        for (int i = m - 2; i >= 0; i--)
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]
            );

        int ans = 0;

        for (int i = 1; i < m; i++) {
            int d = restrictions[i][0] - restrictions[i - 1][0];
            ans = max(ans, (restrictions[i][1] + restrictions[i - 1][1] + d) / 2);
        }

        return max(ans, restrictions.back()[1] + n - restrictions.back()[0]);
    }
};