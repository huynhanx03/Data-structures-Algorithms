/*
 Problem: 2558. Minimum Number of Operations to Sort a Binary Tree by Level
 Language: cpp
 Runtime: 96 ms (68.40%)
 Memory: 194.7 MB (60.80%)
 Tags: Tree, Breadth-First Search, Binary Tree
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
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q;

        int total = 0;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            vector<int> level;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                
                q.pop();

                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            total += solution(level);
        }

        return total;
    }

private:
    int solution(vector<int> a) {
        int n = a.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; ++i) {
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end());

        vector<bool> check(n, false);

        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (check[i] || v[i].second == i)
                continue;

            int cycle_size = 0;

            int j = i;

            while (!check[j]) {
                check[j] = true;
                j = v[j].second;
                cycle_size++;
            }

            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};