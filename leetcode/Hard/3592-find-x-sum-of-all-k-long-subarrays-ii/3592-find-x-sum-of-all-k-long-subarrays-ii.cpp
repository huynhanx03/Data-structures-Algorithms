/*
 Problem: 3592. Find X-Sum of All K-Long Subarrays II
 Language: cpp
 Runtime: 1230 ms (9.26%)
 Memory: 431.1 MB (5.55%)
 Tags: Array, Hash Table, Sliding Window, Heap (Priority Queue)
*/
struct cmp {
    bool operator()(const pair<int, int>& a,
                    const pair<int, int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> freq;
        multiset<pair<int, int>, cmp> topX, rest;
        long long sumTop = 0;
        vector<long long> ans;

        auto moveToRest = [&](auto it) {
            sumTop -= 1LL * it->first * it->second;
            rest.insert(*it);
            topX.erase(it);
        };

        auto moveToTop = [&](auto it) {
            sumTop += 1LL * it->first * it->second;
            topX.insert(*it);
            rest.erase(it);
        };

        auto balance = [&]() {
            while ((int)topX.size() > x) moveToRest(prev(topX.end()));
            while ((int)topX.size() < x && !rest.empty()) moveToTop(rest.begin());
        };

        auto promote = [&]() {
            if (rest.empty() || topX.empty()) return;
            auto a = *rest.begin();
            auto b = *prev(topX.end());
            if (cmp()(a, b)) {
                sumTop -= 1LL * b.first * b.second;
                sumTop += 1LL * a.first * a.second;
                topX.erase(prev(topX.end()));
                rest.erase(rest.begin());
                topX.insert(a);
                rest.insert(b);
            }
        };

        auto add = [&](int v) {
            int f = freq[v]++;
            if (f > 0) {
                pair<int,int> oldp = {v, f};
                if (topX.count(oldp)) {
                    sumTop -= 1LL * v * f;
                    topX.erase(topX.find(oldp));
                } else rest.erase(rest.find(oldp));
            }
            rest.insert({v, f + 1});
            promote();
            balance();
        };

        auto remove = [&](int v) {
            int f = freq[v]--;
            pair<int,int> oldp = {v, f};
            if (topX.count(oldp)) {
                sumTop -= 1LL * v * f;
                topX.erase(topX.find(oldp));
            } else rest.erase(rest.find(oldp));
            if (f > 1) rest.insert({v, f - 1});
            else freq.erase(v);
            promote();
            balance();
        };

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= k) remove(nums[i - k]);
            if (i >= k - 1) ans.push_back(sumTop);
        }

        return ans;
    }
};
