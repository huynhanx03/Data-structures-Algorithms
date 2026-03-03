/*
 Problem: 74. Search a 2D Matrix
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 13.4 MB (7.86%)
 Tags: Array, Binary Search, Matrix
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int l = 0;
        int r = n - 1;
        int c = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (target >= matrix[mid][0]) {
                l = mid + 1;
                c = mid;
            }
            else
                r = mid - 1;
        }

        c = c == -1 ? l : c;
        l = 0;
        r = m - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (target == matrix[c][mid])
                return true;

            if (target > matrix[c][mid])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};