/*
 Problem: 4143. Number of Alternating XOR Partitions
 Language: cpp
 Runtime: 70 ms (55.16%)
 Memory: 139.6 MB (63.28%)
 Tags: Array, Hash Table, Dynamic Programming, Bit Manipulation
*/
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
         long long MOD = 1e9 + 7;

        unordered_map<int, long long> cnt0;
        unordered_map<int, long long> cnt1;

        cnt0[0] = 1;
        int cur_xor = 0;
        long long t1 = 0, t2 = 0;
        for (const auto& x : nums) {
            cur_xor ^= x;

            int n1 = cur_xor ^ target1;
            if (cnt0.count(n1)) {
                t1 = cnt0[n1];
            } else {
                t1 = 0;
            }

            int n2 = cur_xor ^ target2;
            if (cnt1.count(n2)) {
                t2 = cnt1[n2];
            } else {
                t2 = 0;
            }

            cnt1[cur_xor] = (cnt1[cur_xor] + t1) % MOD;
            cnt0[cur_xor] = (cnt0[cur_xor] + t2) % MOD;
        }

        return (t1 + t2) % MOD;
    }
};