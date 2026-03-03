/*
 Problem: 2792. Neighboring Bitwise XOR
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 264 MB (47.86%)
 Tags: Array, Bit Manipulation
*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int v = derived[0];

        for (int i = 1; i < n; ++i)
            v ^= derived[i];

        return v == 0;
    }
};