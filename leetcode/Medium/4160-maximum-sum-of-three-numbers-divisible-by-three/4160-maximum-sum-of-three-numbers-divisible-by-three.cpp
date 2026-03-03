/*
 Problem: 4160. Maximum Sum of Three Numbers Divisible by Three
 Language: cpp
 Runtime: 236 ms (29.04%)
 Memory: 292.1 MB (14.48%)
 Tags: Array, Greedy, Sorting, Heap (Priority Queue)
*/
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector <vector<int>> dim(3);

        for (const auto& x : nums) {
            dim[x % 3].push_back(x);
        }

        int s = 0;
        for (auto& d : dim) {
            sort(d.rbegin(), d.rend());
        }

        if (dim[0].size() >= 3) {
            s = max(s, dim[0][0] + dim[0][1] + dim[0][2]);
        }

        if (dim[1].size() >= 3) {
            s = max(s, dim[1][0] + dim[1][1] + dim[1][2]);
        }

        if (dim[2].size() >= 3) {
            s = max(s, dim[2][0] + dim[2][1] + dim[2][2]);
        }

        if (!dim[0].empty() && !dim[1].empty() && !dim[2].empty()) {
            s = max(s, dim[0][0] + dim[1][0] + dim[2][0]);
        }

        return s;
    }
};