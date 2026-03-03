/*
 Problem: 4146. Total Score of Dungeon Runs
 Language: cpp
 Runtime: 40 ms (84.86%)
 Memory: 254.3 MB (39.45%)
 Tags: Array, Binary Search, Prefix Sum
*/
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();

        vector <long long> pre(n + 5, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + damage[i];
        }

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            long long limit = (long long) hp - requirement[i];

            if (limit < 0) continue;

            long long need = pre[i + 1] - limit;
            int pos = lower_bound(pre.begin(), pre.begin() + i + 1, need) - pre.begin();
            
            ans += (i - pos + 1);
        }
         
        return ans;
    }
};