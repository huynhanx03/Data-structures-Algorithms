/*
 Problem: 3928. Split and Merge Array Transformation
 Language: cpp
 Runtime: 228 ms (78.07%)
 Memory: 89.3 MB (74.87%)
 Tags: Array, Hash Table, Breadth-First Search
*/
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> donquarist = nums1;
        if (nums1 == nums2)
            return 0;
        queue<pair<vector<int>, int>> q;
        set<vector<int>> vis;
        q.push({nums1, 0});
        vis.insert(nums1);
        int n = nums1.size();
        while (!q.empty()) {
            auto [cur, d] = q.front();
            q.pop();
            for (int L = 0; L < n; L++) {
                for (int R = L; R < n; R++) {
                    vector<int> sub(cur.begin() + L, cur.begin() + R + 1);
                    vector<int> rem;
                    for (int i = 0; i < n; i++)
                        if (i < L || i > R)
                            rem.push_back(cur[i]);
                    for (int pos = 0; pos <= (int)rem.size(); pos++) {
                        vector<int> nxt = rem;
                        nxt.insert(nxt.begin() + pos, sub.begin(), sub.end());
                        if (vis.count(nxt))
                            continue;
                        if (nxt == nums2)
                            return d + 1;
                        vis.insert(nxt);
                        q.push({nxt, d + 1});
                    }
                }
            }
        }
        return -1;
    }
};
