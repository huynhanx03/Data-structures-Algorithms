/*
 Problem: 189. Rotate Array
 Language: cpp
 Runtime: 21 ms (1.77%)
 Memory: 28.1 MB (100.00%)
 Tags: Array, Math, Two Pointers
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        vector<int> a(n);

        if (k != 0) {
            // a[i] = a[(i + k) % n]
            for (int i = 0; i < n; ++i)
                a[i] = nums[(n - k + i) % n];

            nums = a;
        }
    }
};