/*
 Problem: 4079. Maximum Capacity Within Budget
 Language: cpp
 Runtime: 119 ms (39.72%)
 Memory: 272.4 MB (33.21%)
 Tags: Array, Two Pointers, Binary Search, Sorting
*/
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back({costs[i], capacity[i]});
        }

        sort(v.begin(), v.end());

        vector <int> mx(n);
        mx[0] = v[0].second;
        for (int i = 1; i < n; ++i) {
            mx[i] = max(mx[i - 1], v[i].second);
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (v[i].first < budget) {
                ans = max(ans, v[i].second);
            }
        }

        for (int i = 0; i < n; ++i) {
            int rem = budget - v[i].first;
            if (rem <= 0) continue;

            int l = 0, r = i - 1, best = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
            
                if (v[mid].first < rem) {
                    l = mid + 1;
                    best = mid;
                } else {
                    r = mid - 1;
                }
            }

            if (best != -1) {
                ans = max(ans, v[i].second + mx[best]);
            }
        }
        
        return ans;
    }
};