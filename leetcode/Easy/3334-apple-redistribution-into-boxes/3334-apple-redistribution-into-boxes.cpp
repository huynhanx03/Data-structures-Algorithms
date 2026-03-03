/*
 Problem: 3334. Apple Redistribution into Boxes
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 33.1 MB (75.19%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long totalApples = 0;
        for (const auto& a : apple) totalApples += a;

        sort(capacity.begin(), capacity.end(), greater<int>());

        long long cur = 0;
        int cnt = 0;

        for (const auto& c : capacity) {
            cur += c;
            ++cnt;
            if (cur >= totalApples) return cnt;
        }

        return cnt;
    }
};
