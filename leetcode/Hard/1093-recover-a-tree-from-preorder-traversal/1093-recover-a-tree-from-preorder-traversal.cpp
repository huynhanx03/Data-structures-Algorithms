/*
 Problem: 1093. Recover a Tree From Preorder Traversal
 Language: cpp
 Runtime: 3 ms (56.49%)
 Memory: 21.7 MB (31.82%)
 Tags: String, Tree, Depth-First Search, Binary Tree
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
class Solution
{
private:
    int n;

    TreeNode* dfs(string& traversal, int& index, int depth)
    {
        if (index >= n)
        {
            return nullptr;
        }

        int d = 0;
        while (index < n && traversal[index] == '-')
        {
            ++d;
            ++index;
        }

        if (d != depth)
        {
            index -= d;
            return nullptr;
        }

        int val = 0;
        while (index < n && traversal[index] != '-')
        {
            val = val * 10 + (int)(traversal[index] - '0');
            ++index;
        }

        TreeNode *node = new TreeNode(val);
        node->left = dfs(traversal, index, depth + 1);
        node->right = dfs(traversal, index, depth + 1);

        return node;
    }

public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        n = traversal.size();
        
        int index = 0;

        return dfs(traversal, index, 0);
    }
};