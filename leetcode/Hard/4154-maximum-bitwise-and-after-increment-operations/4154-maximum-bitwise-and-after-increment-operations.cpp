/*
 Problem: 4154. Maximum Bitwise AND After Increment Operations
 Language: cpp
 Runtime: 298 ms (47.62%)
 Memory: 229 MB (33.32%)
 Tags: Array, Greedy, Bit Manipulation, Sorting
*/
class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int ans = 0;

        for (int b = 30; b >= 0; --b) {
            long long tmp = ans | (1LL << b);
            vector <long long> costs;

            for (const auto& x : nums) {
                long long cost = 0;
                int mis = -1;

                for (int i = 30; i >= b; --i) {
                    if (((tmp >> i) & 1) == 1 && ((x >> i) & 1) == 0) {
                        mis = i;
                        break;
                    }
                }

                if (mis != -1) {
                    long long target = ((long long) (x >> (mis + 1))) << (mis + 1);
                    target |= (1LL << mis);
                    target |= (tmp & ((1LL << mis) - 1));
                    cost = target - x;
                }
                
                costs.push_back(cost);
            }

            sort(costs.begin(), costs.end());
            long long c = 0;
            bool check = true;

            for (int i = 0; i < m; ++i) {
                c += costs[i];
                if (c > k) {
                    check = false;
                    break;
                }
            }

            if (check) {
                ans = tmp;
            }
        }
        
        return ans;
    }
};