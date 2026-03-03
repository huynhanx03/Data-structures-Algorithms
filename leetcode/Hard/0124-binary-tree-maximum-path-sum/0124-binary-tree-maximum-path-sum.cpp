/*
 Problem: 124. Binary Tree Maximum Path Sum
 Language: cpp
 Runtime: 19 ms (4.85%)
 Memory: 26.3 MB (99.97%)
 Tags: Dynamic Programming, Tree, Depth-First Search, Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = -1e9;

    int maxPathSum(TreeNode* root) {
        maxSum(root);

        return ans;
    }

    int maxSum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int l = max(0, maxSum(root->left));
        int r = max(0, maxSum(root->right));

        int sum = root->val + l + r;

        ans = max(ans, sum);

        return root->val + max(l, r);
    }
};