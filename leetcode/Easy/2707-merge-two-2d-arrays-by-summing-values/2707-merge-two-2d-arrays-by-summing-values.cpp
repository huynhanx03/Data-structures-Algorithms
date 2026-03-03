/*
 Problem: 2707. Merge Two 2D Arrays by Summing Values
 Language: cpp
 Runtime: 3 ms (29.19%)
 Memory: 14.7 MB (83.57%)
 Tags: Array, Hash Table, Two Pointers
*/
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l1 = 0, l2 = 0;

        vector<vector<int>> res;

        while (l1 < n1 && l2 < n2) {
            if (nums1[l1][0] == nums2[l2][0]) {
                res.push_back(
                    vector<int>{nums1[l1][0], nums1[l1++][1] + nums2[l2++][1]});
            } else if (nums1[l1][0] < nums2[l2][0]) {
                res.push_back(vector<int>{nums1[l1][0], nums1[l1][1]});
                ++l1;
            } else {
                res.push_back(vector<int>{nums2[l2][0], nums2[l2][1]});
                ++l2;
            }
        }

        while (l1 < n1) {
            res.push_back(vector<int>{nums1[l1][0], nums1[l1][1]});
            ++l1;
        }

        while (l2 < n2) {
            res.push_back(vector<int>{nums2[l2][0], nums2[l2][1]});
            ++l2;
        }

        return res;
    }
};