/*
 Problem: 2533. Bitwise XOR of All Pairings
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 64.4 MB (14.93%)
 Tags: Array, Bit Manipulation, Brainteaser
*/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // a1 xor b1..bn
        // a2 xor b1..bn
        // b1..bn  xor a1 xor

        int n1 = nums1.size(), n2 = nums2.size();

        int ans = 0;

        if (n2 % 2 == 1)
            for (int i = 0; i < n1; ++i)
                ans ^= nums1[i];

        if (n1 % 2 == 1)
            for (int i = 0; i < n2; ++i)
                ans ^= nums2[i];

        return ans;
    }
};