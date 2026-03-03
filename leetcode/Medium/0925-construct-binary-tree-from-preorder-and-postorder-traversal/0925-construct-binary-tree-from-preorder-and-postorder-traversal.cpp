/*
 Problem: 925. Construct Binary Tree from Preorder and Postorder Traversal
 Language: cpp
 Runtime: 4 ms (25.83%)
 Memory: 28.1 MB (79.01%)
 Tags: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
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
    int pPre = 0;
    int pPost = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // pre --> NLR
        // post -> LRN
        TreeNode* node = new TreeNode(preorder[pPre++]);

        if (node->val != postorder[pPost]) {
            node->left = constructFromPrePost(preorder, postorder);
        }

        if (node->val != postorder[pPost]) {
            node->right = constructFromPrePost(preorder, postorder);
        }

        ++pPost;

        return node;
    }
};