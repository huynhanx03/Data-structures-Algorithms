/*
 Problem: 4150. Sort Integers by Binary Reflection
 Language: cpp
 Runtime: 3 ms (82.81%)
 Memory: 32.3 MB (99.64%)
 Tags: Array, Sorting
*/
class Solution {
private:
    int ref(int x) {
        int res = 0;
        while (x > 0) {
            res = (res << 1) | (x & 1);
            x /= 2;
        }
        return res;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int bA = ref(a);
            int bB = ref(b);

            if (bA != bB) {
                return bA < bB;
            }

            return a < b;
        });

        return nums;
    }
};