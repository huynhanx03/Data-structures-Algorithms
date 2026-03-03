/*
 Problem: 637. Average of Levels in Binary Tree
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 24 MB (23.26%)
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);

        int cnt = 1;

        vector<double> result;

        while (!qu.empty()) {
            long long av = 0;
            int count = 0;

            for (int i = 0; i < cnt; ++i) {
                auto t = qu.front();
                qu.pop();

                av += t->val;

                if (t->left) {
                    ++count;
                    qu.push(t->left);
                }

                if (t->right) {
                    ++count;
                    qu.push(t->right);
                }
            }

            result.push_back((double) av / cnt);
            cnt = count;
        }

        return result;
    }
};