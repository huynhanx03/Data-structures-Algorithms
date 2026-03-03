/*
 Problem: 108. Convert Sorted Array to Binary Search Tree
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 22.8 MB (81.31%)
 Tags: Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size() - 1);
    }

    TreeNode* bst(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = bst(nums, left, mid - 1);
        node->right = bst(nums, mid + 1, right);

        return node;
    }
};