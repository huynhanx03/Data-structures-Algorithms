/*
 Problem: 235. Lowest Common Ancestor of a Binary Search Tree
 Language: cpp
 Runtime: 20 ms (79.21%)
 Memory: 23.4 MB (90.56%)
 Tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};