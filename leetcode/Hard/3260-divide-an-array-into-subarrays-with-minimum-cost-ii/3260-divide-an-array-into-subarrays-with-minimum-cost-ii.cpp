/*
 Problem: 3260. Divide an Array Into Subarrays With Minimum Cost II
 Language: cpp
 Runtime: 530 ms (6.88%)
 Memory: 190.2 MB (6.58%)
 Tags: Array, Hash Table, Sliding Window, Heap (Priority Queue)
*/
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        if (k == 1) return nums[0];
        
        int n = nums.size();
        long long ans = LLONG_MAX;
        int K = k - 2;
        
        multiset<int> L, R;
        long long sumL = 0;
        
        auto add = [&](int val) {
            L.insert(val);
            sumL += val;
            if (L.size() > K) {
                int largest = *L.rbegin();
                L.erase(prev(L.end()));
                sumL -= largest;
                R.insert(largest);
            }
        };
        
        auto remove = [&](int val) {
            auto it = R.find(val);
            if (it != R.end()) {
                R.erase(it);
            } else {
                it = L.find(val);
                if (it != L.end()) {
                    L.erase(it);
                    sumL -= val;
                    if (!R.empty()) {
                        int smallest = *R.begin();
                        R.erase(R.begin());
                        L.insert(smallest);
                        sumL += smallest;
                    }
                }
            }
        };
        
        for (int j = 2; j <= min(1 + dist, n - 1); ++j) {
            add(nums[j]);
        }
        
        for (int i = 1; i < n; ++i) {
            if (L.size() == K) {
                ans = min(ans, (long long)nums[0] + nums[i] + sumL);
            }
            
            if (i + 1 < n) {
                remove(nums[i + 1]);
                if (i + 1 + dist < n) {
                    add(nums[i + 1 + dist]);
                }
            }
        }
        
        return ans;
    }
};