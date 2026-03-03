/*
 Problem: 230. Kth Smallest Element in a BST
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 24.3 MB (66.29%)
 Tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
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
    int cnt = 0;
    int result = -1;

    void inOrderTraversal(TreeNode* root, int& k) {
        if (!root)
            return;

        inOrderTraversal(root->left, k);

        cnt++;
        if (cnt == k) {
            result = root->val;
            return;
        }

        inOrderTraversal(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k);
        return result;
    }
};
