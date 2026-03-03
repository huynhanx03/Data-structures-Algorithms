/*
 Problem: 2649. Count Total Number of Colored Cells
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.9 MB (65.18%)
 Tags: Math
*/
class Solution {
public:
    long long coloredCells(int n) {
        return 1LL * n * n * 2 - max(0, 2 * n - 1);
    }
};