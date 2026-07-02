/*
 Problem: 4303. Count K-th Roots in a Range
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.9 MB (22.56%)
 Tags: Math, Binary Search
*/
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        auto get = [&](int x) {
            return pow(x, 1.0 / k);
        };

        return max(0, (int) (
            floor(get(r) + 1e-9) - 
            ceil(get(l) - 1e-9) + 1)
        );
    }
};