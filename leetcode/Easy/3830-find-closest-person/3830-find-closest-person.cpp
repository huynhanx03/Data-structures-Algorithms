/*
 Problem: 3830. Find Closest Person
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.5 MB (52.70%)
 Tags: Math
*/
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int cx = abs(z - x);
        int cy = abs(z - y);

        return cx == cy ? 0 : cx > cy ? 2 : 1;
    }
};