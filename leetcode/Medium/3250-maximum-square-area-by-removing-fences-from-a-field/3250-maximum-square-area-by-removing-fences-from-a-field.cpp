/*
 Problem: 3250. Maximum Square Area by Removing Fences From a Field
 Language: cpp
 Runtime: 1773 ms (20.83%)
 Memory: 445.7 MB (25.68%)
 Tags: Array, Hash Table, Enumeration
*/
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        // Add borders
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> heights, widths;

        // All possible heights
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                heights.insert(hFences[j] - hFences[i]);
            }
        }

        // All possible widths
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                widths.insert(vFences[j] - vFences[i]);
            }
        }

        long long maxSide = 0;
        for (int h : heights) {
            if (widths.count(h)) {
                maxSide = max(maxSide, (long long)h);
            }
        }

        if (maxSide == 0) return -1;
        return (maxSide * maxSide) % MOD;
    }
};
