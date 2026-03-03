/*
 Problem: 1285. Balance a Binary Search Tree
 Language: cpp
 Runtime: 15 ms (50.75%)
 Memory: 65.7 MB (39.36%)
 Tags: Divide and Conquer, Greedy, Tree, Depth-First Search, Binary Search Tree, Binary Tree
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
    vector<int> vals;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;

        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(vals[mid]);

        node->left  = build(l, mid - 1);
        node->right = build(mid + 1, r);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, vals.size() - 1);
    }
};
