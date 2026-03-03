/*
 Problem: 3640. Maximum Frequency of an Element After Performing Operations II
 Language: cpp
 Runtime: 336 ms (73.82%)
 Memory: 104.3 MB (79.71%)
 Tags: Array, Binary Search, Sliding Window, Sorting, Prefix Sum
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> vals;
        vals.reserve(nums.size() * 3);
        for (int x : nums) {
            vals.push_back(x);
            vals.push_back(x - k);
            vals.push_back(x + k);
        }

        // Nén số
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        vector<int> freq(m, 0);

        // Đếm tần suất theo chỉ số nén
        for (int x : nums) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
            freq[idx]++;
        }

        // Prefix sum
        vector<int> prefix(m, 0);
        prefix[0] = freq[0];
        for (int i = 1; i < m; i++) prefix[i] = prefix[i - 1] + freq[i];

        int ans = 0;
        for (int i = 0; i < m; i++) {
            int cur = freq[i];
            long long center = vals[i];
            long long left_val = center - k;
            long long right_val = center + k;

            // Tìm index tương ứng với khoảng [center - k, center + k]
            int left = lower_bound(vals.begin(), vals.end(), left_val) - vals.begin();
            int right = upper_bound(vals.begin(), vals.end(), right_val) - vals.begin() - 1;

            // Tổng số phần tử trong [left, right], trừ phần tử trung tâm
            int allVal = prefix[right] - (left > 0 ? prefix[left - 1] : 0) - cur;

            ans = max(ans, min(allVal, numOperations) + cur);
        }

        return ans;
    }
};