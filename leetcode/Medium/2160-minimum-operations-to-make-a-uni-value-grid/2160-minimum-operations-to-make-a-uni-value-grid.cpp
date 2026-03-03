/*
 Problem: 2160. Minimum Operations to Make a Uni-Value Grid
 Language: cpp
 Runtime: 49 ms (35.00%)
 Memory: 90.2 MB (40.42%)
 Tags: Array, Math, Sorting, Matrix
*/
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // value vs k*x
        vector <int> arr;

        for (const auto& v : grid) {
            for (const auto& x: v) arr.push_back(x);
        }

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int pos = n / 2;
        int mid = arr[pos];
        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (i == pos) continue;

            int diff = abs(arr[i] - mid);

            if (diff % x != 0) return -1;

            res += diff / x;
        }

        return res;
    }
};