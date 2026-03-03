/*
 Problem: 129. Sum Root to Leaf Numbers
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 10.9 MB (100.00%)
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
public:
    int NumberTree(TreeNode* root, int value) {
        int sum = 0;

        if (root->left == nullptr && root->right == nullptr)
            return value;
        
        if (root->left != nullptr) 
            sum += NumberTree(root->left, value * 10 + root->left->val);

        if (root->right != nullptr) 
            sum += NumberTree(root->right, value * 10 + root->right->val);

        return sum;
    }

    int sumNumbers(TreeNode* root) {
        return NumberTree(root, root->val);
    }
};