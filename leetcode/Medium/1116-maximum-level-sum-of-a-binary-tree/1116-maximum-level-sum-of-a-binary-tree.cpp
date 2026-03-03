/*
 Problem: 1116. Maximum Level Sum of a Binary Tree
 Language: cpp
 Runtime: 4 ms (54.69%)
 Memory: 109.2 MB (80.67%)
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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int answerLevel = 1;
        long long maxSum = LLONG_MIN;

        while (!q.empty()) {
            int sz = q.size();
            long long curSum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                curSum += node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (curSum > maxSum) {
                maxSum = curSum;
                answerLevel = level;
            }

            level++;
        }

        return answerLevel;
    }
};
