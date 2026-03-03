/*
 Problem: 1001. N-Repeated Element in Size 2N Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 28.3 MB (96.87%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        for (int i = 0; i + 1 < a.size(); ++i)
            if (a[i] == a[i + 1] || (i + 2 < a.size() && a[i] == a[i + 2]))
                return a[i];
        return a[0];
    }
};