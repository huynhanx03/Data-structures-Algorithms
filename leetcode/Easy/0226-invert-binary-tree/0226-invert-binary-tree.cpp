/*
 Problem: 226. Invert Binary Tree
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.7 MB (100.00%)
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* cur = root->left;
        root->left = root->right;
        root->right = cur;
        
        invertTree(root->left);
        invertTree(root->right);

        
        return root;
    }
};