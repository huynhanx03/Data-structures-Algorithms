/*
 Problem: 1218. Lowest Common Ancestor of Deepest Leaves
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 22.1 MB (67.82%)
 Tags: Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
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
private:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node)
            return {0, nullptr};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if (left.first == right.first) {
            return {left.first + 1, node};
        } else if (left.first > right.first) {
            return {left.first + 1, left.second};
        } else {
            return {right.first + 1, right.second};
        }
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).second; }
};