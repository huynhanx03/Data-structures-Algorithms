/*
 Problem: 441. Arranging Coins
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.9 MB (35.85%)
 Tags: Math, Binary Search
*/
class Solution {
public:
    int arrangeCoins(int n) {
        return static_cast<int>(sqrt(2.0 * static_cast<long>(n) + 0.25) - 0.5);
    }
};