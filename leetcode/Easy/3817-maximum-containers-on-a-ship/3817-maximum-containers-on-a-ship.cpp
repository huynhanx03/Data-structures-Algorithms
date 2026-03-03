/*
 Problem: 3817. Maximum Containers on a Ship
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.5 MB (1.80%)
 Tags: Math
*/
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        return min(n * n, maxWeight / w);
    }
};