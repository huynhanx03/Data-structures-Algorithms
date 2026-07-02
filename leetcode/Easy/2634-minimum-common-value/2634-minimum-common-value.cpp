/*
 Problem: 2634. Minimum Common Value
 Language: cpp
 Runtime: 1 ms (34.18%)
 Memory: 54.6 MB (56.00%)
 Tags: Array, Hash Table, Two Pointers, Binary Search
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] == nums2[p2]) return nums1[p1];

            if (nums1[p1] < nums2[p2]) ++p1;
            else ++p2;
        }

        return -1;
    }
};