/*
 Problem: 2491. Smallest Even Multiple
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.8 MB (93.71%)
 Tags: Math, Number Theory
*/
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
    }
};