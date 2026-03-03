/*
 Problem: 3279. Alice and Bob Playing Flower Game
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.6 MB (11.83%)
 Tags: Math
*/
class Solution {
public:
    long long flowerGame(int n, int m) {
        long oddN = (n + 1) / 2, evenN = n / 2;
        long oddM = (m + 1) / 2, evenM = m / 2;
        return oddN * evenM + evenN * oddM;
    }
};