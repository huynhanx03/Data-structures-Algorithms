/*
 Problem: 543. Diameter of Binary Tree
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 23.8 MB (19.08%)
 Tags: Tree, Depth-First Search, Binary Tree
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
private:
    int height(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        diameter = std::max(diameter, leftHeight + rightHeight);
        return 1 + std::max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};