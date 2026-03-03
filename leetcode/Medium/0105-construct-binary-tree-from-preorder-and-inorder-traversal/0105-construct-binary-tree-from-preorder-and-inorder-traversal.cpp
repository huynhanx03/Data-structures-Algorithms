/*
 Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 27.6 MB (34.20%)
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inorder_map);
    }

private:
    TreeNode* build(vector<int>& preorder, int pre_left, int pre_right,
                    vector<int>& inorder, int in_left, int in_right,
                    unordered_map<int, int>& inorder_map) {
        if (pre_left > pre_right || in_left > in_right) {
            return nullptr;
        }

        int root_val = preorder[pre_left];
        TreeNode* root = new TreeNode(root_val);
        int root_index = inorder_map[root_val];
        int left_tree_size = root_index - in_left;

        root->left = build(preorder, pre_left + 1, pre_left + left_tree_size,
                           inorder, in_left, root_index - 1, inorder_map);
        root->right = build(preorder, pre_left + left_tree_size + 1, pre_right,
                            inorder, root_index + 1, in_right, inorder_map);

        return root;
    }
};