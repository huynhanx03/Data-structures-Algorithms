/*
 Problem: 3610. Find X-Sum of All K-Long Subarrays I
 Language: cpp
 Runtime: 5 ms (93.40%)
 Memory: 32.4 MB (82.57%)
 Tags: Array, Hash Table, Sliding Window, Heap (Priority Queue)
*/
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> freq;
        multiset<pair<int, int>, cmp> order; // (value, freq)
        vector<int> ans;

        auto add = [&](int v) {
            int f = freq[v]++;
            if (f > 0)
                order.erase(order.find({v, f}));
            order.insert({v, f + 1});
        };

        auto remove = [&](int v) {
            int f = freq[v]--;
            order.erase(order.find({v, f}));
            if (f > 1)
                order.insert({v, f - 1});
            else
                freq.erase(v);
        };

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= k)
                remove(nums[i - k]);
            if (i >= k - 1) {
                int sum = 0;
                int count = 0;
                for (auto it = order.begin(); it != order.end() && count < x;
                     ++it, ++count) {
                    auto [val, f] = *it;
                    sum += val * f;
                }
                ans.push_back(sum);
            }
        }

        return ans;
    }
};