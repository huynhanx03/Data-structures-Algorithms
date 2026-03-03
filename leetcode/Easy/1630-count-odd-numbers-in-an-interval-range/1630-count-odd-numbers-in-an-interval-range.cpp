/*
 Problem: 1630. Count Odd Numbers in an Interval Range
 Language: cpp
 Runtime: 2 ms (74.99%)
 Memory: 7.8 MB (69.92%)
 Tags: Math
*/
class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};