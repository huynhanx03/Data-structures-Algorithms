/*
 Problem: 3750. Closest Equal Element Queries
 Language: cpp
 Runtime: 181 ms (83.58%)
 Memory: 217.1 MB (30.35%)
 Tags: Array, Hash Table, Binary Search
*/
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }

        vector<int> dist(n);

        for (const auto& [_, arr] : mp) {
            int m = arr.size();
            if (m == 1) {
                dist[arr[0]] = -1;
                continue;
            }

            for (int i = 0; i < m; ++i) {
                int cur = arr[i];
                int l = arr[(i - 1 + m) % m];
                int r = arr[(i + 1) % m];

                int d1 = abs(cur - l);
                int d2 = abs(cur - r);

                d1 = min(d1, n - d1);
                d2 = min(d2, n - d2);

                dist[cur] = min(d1, d2);
            }
        }

        vector<int> res;
        res.reserve(queries.size());
        for (const auto& q : queries)
            res.push_back(dist[q]);

        return res;
    }
};