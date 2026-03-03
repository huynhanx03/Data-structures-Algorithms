/*
 Problem: 3824. Number of Unique XOR Triplets I
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 199.1 MB (9.62%)
 Tags: Array, Math, Bit Manipulation
*/
class Solution {
private:
    int pow2(int n) {
        if (n == 0) return 1;
        int x = pow2(n / 2);
        int res = x * x;
        if (n & 1) res *= 2;
        return res;
    }

public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return n;

        int nearest = (int)floor(log2(n));
        return pow2(nearest + 1);
    }
};