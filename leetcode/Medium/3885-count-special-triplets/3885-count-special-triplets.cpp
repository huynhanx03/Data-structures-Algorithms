/*
 Problem: 3885. Count Special Triplets
 Language: cpp
 Runtime: 1217 ms (8.60%)
 Memory: 342.7 MB (79.42%)
 Tags: Array, Hash Table, Counting
*/
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        map <long long, long long> leftCount, rightCount;

        for (const auto&x : nums) ++rightCount[x];

        long long res = 0;

        for (int j = 0; j < nums.size(); j++) {
            long long v = nums[j];
            --rightCount[v];

            long long target = v * 2;
            long long left = leftCount.count(target) ? leftCount[target] : 0;
            long long right = rightCount.count(target) ? rightCount[target] : 0;

            res = (res + (left * right) % MOD) % MOD;

            leftCount[v]++;
        }

        return (int)res;
    }
};
