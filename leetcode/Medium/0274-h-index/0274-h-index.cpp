/*
 Problem: 274. H-Index
 Language: cpp
 Runtime: 5 ms (7.63%)
 Memory: 10.9 MB (100.00%)
 Tags: Array, Sorting, Counting Sort
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int n = citations.size();

        int ans = 0;

        for (int i = n - 1; i >=0; --i) {
            if (citations[i] >= ans + 1)
                ++ans;
        }
        
        return ans;
    }
};