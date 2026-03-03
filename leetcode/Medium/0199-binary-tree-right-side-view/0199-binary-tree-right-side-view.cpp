/*
 Problem: 199. Binary Tree Right Side View
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14.8 MB (85.14%)
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
    vector<int> rightSideView(TreeNode* root) {
        insert(root, 0);
        return res;
    }

private:
    vector<int> res;
    int maxDepth = -1;

    void insert(TreeNode* r, int depth) {
        if (!r) return;

        if (depth > maxDepth) {
            res.push_back(r->val);
            maxDepth = depth;
        }

        insert(r->right, depth + 1);
        insert(r->left, depth + 1);
    }
};
