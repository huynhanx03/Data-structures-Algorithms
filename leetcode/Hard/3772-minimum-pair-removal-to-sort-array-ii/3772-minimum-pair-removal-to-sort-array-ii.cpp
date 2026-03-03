/*
 Problem: 3772. Minimum Pair Removal to Sort Array II
 Language: cpp
 Runtime: 952 ms (24.99%)
 Memory: 314.9 MB (9.90%)
 Tags: Array, Hash Table, Linked List, Heap (Priority Queue), Simulation, Doubly-Linked List, Ordered Set
*/
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<long long> v(nums.begin(), nums.end());
        vector<int> l(n), r(n);
        
        for (int i = 0; i < n; ++i) {
            l[i] = i - 1;
            r[i] = i + 1;
        }
        r[n - 1] = -1;

        set<pair<long long, int>> s;
        int bad = 0;

        auto isBad = [&](int i) {
            if (i == -1 || r[i] == -1) return false;
            return v[i] > v[r[i]];
        };

        for (int i = 0; i < n - 1; ++i) {
            s.insert({v[i] + v[i + 1], i});
            if (v[i] > v[i + 1]) ++bad;
        }

        int ops = 0;
        while (bad > 0) {
            int i = s.begin()->second;
            int j = r[i];

            if (l[i] != -1) {
                s.erase({v[l[i]] + v[i], l[i]});
                if (isBad(l[i])) --bad;
            }
            
            s.erase({v[i] + v[j], i});
            if (isBad(i)) --bad;

            if (r[j] != -1) {
                s.erase({v[j] + v[r[j]], j});
                if (isBad(j)) --bad;
            }

            v[i] += v[j];
            r[i] = r[j];
            if (r[i] != -1) l[r[i]] = i;

            if (l[i] != -1) {
                s.insert({v[l[i]] + v[i], l[i]});
                if (isBad(l[i])) ++bad;
            }

            if (r[i] != -1) {
                s.insert({v[i] + v[r[i]], i});
                if (isBad(i)) ++bad;
            }

            ops++;
        }

        return ops;
    }
};