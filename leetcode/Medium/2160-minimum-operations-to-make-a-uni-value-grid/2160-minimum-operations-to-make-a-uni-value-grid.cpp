/*
 Problem: 2160. Minimum Operations to Make a Uni-Value Grid
 Language: cpp
 Runtime: 55 ms (15.85%)
 Memory: 90 MB (57.50%)
 Tags: Array, Math, Sorting, Matrix
*/
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector <int> arr;

        for (const auto& v : grid) {
            for (const auto& x: v) arr.emplace_back(x);
        }

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int mid = arr[n / 2];
        int res = 0;

        for (int i = 0; i < n; ++i) {
            int diff = abs(arr[i] - mid);
            if (diff % x != 0) return -1;
            res += diff / x;
        }

        return res;
    }
};