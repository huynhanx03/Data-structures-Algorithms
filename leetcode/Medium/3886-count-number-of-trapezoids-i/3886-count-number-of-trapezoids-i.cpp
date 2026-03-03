/*
 Problem: 3886. Count Number of Trapezoids I
 Language: cpp
 Runtime: 66 ms (60.14%)
 Memory: 195.5 MB (95.29%)
 Tags: Array, Hash Table, Math, Geometry
*/
class Solution {
private:
    const long long MOD = 1000000007;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> cnt;
        for (auto &p : points) cnt[p[1]]++;

        long long sumC = 0, sumSq = 0;
        for (auto &kv : cnt) {
            long long k = kv.second;
            if (k >= 2) {
                long long c = (k * (k - 1) / 2) % MOD;
                sumC = (sumC + c) % MOD;
                sumSq = (sumSq + (c * c) % MOD) % MOD;
            }
        }

        long long res = ( (sumC * sumC) % MOD - sumSq + MOD ) % MOD;
        res = res * ((MOD + 1) / 2) % MOD;
        return (int)res;
    }
};
