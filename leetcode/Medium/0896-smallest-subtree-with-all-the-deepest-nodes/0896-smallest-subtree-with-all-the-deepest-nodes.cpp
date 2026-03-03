/*
 Problem: 896. Smallest Subtree with all the Deepest Nodes
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 16.1 MB (83.58%)
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto [dl, nl] = dfs(root->left);
        auto [dr, nr] = dfs(root->right);

        if (dl == dr) return {dl+1, root};
        else if (dl > dr) return {dl+1, nl};
        else return {dr+1, nr};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
