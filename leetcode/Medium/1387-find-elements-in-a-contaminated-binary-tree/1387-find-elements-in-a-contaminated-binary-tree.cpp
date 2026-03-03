/*
 Problem: 1387. Find Elements in a Contaminated Binary Tree
 Language: cpp
 Runtime: 269 ms (11.33%)
 Memory: 25.6 MB (99.73%)
 Tags: Hash Table, Tree, Depth-First Search, Breadth-First Search, Design, Binary Tree
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
class FindElements {
private:
    TreeNode* root;

    void build(TreeNode* node, int value) {
        if (!node) return;

        node->val = value;
        if (node->left) build(node->left, 2 * value + 1);
        if (node->right) build(node->right, 2 * value + 2);
    }

    bool findInTree(TreeNode* node, int target) {
        if (!node) return false;
        if (node->val == target) return true;
        return findInTree(node->left, target) || findInTree(node->right, target);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        build(root, 0);
    }
    
    bool find(int target) {
        return findInTree(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */