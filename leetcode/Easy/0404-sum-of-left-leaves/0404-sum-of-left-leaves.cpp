/*
 Problem: 404. Sum of Left Leaves
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14.8 MB (99.96%)
 Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
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
    int valueLeft(TreeNode* root, bool isAdd) {
        int sum = 0;

        if (root->left == nullptr && root->right == nullptr && isAdd)
            return root->val;
        
        if (root->left != nullptr) 
            sum += valueLeft(root->left, 1);

        if (root->right != nullptr) 
            sum += valueLeft(root->right, 0);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return valueLeft(root, 0);
    }
};