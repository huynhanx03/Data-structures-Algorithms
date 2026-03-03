/*
 Problem: 3791. Fruits Into Baskets III
 Language: cpp
 Runtime: 341 ms (26.26%)
 Memory: 295.6 MB (5.03%)
 Tags: Array, Binary Search, Segment Tree, Ordered Set
*/
#include <vector>
using namespace std;

class SegmentTreeNode {
public:
    int l, r;
    int max_cap;
    int min_cap;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    
    SegmentTreeNode(int l, int r) : l(l), r(r), max_cap(0), min_cap(0), left(nullptr), right(nullptr) {}
};

class SegmentTree {
private:
    vector<int> baskets;
    int n;
    
    SegmentTreeNode* build_tree(int l, int r) {
        auto node = new SegmentTreeNode(l, r);
        if (l == r) {
            node->max_cap = baskets[l];
            node->min_cap = baskets[l];
            return node;
        }
        int mid = l + (r - l) / 2;
        node->left = build_tree(l, mid);
        node->right = build_tree(mid + 1, r);
        node->max_cap = max(node->left->max_cap, node->right->max_cap);
        node->min_cap = min(node->left->min_cap, node->right->min_cap);
        return node;
    }
    
    void update_tree(SegmentTreeNode* node, int idx, int val) {
        if (node->l == node->r) {
            node->max_cap = val;
            node->min_cap = val;
            return;
        }
        int mid = node->l + (node->r - node->l) / 2;
        if (idx <= mid) {
            update_tree(node->left, idx, val);
        } else {
            update_tree(node->right, idx, val);
        }
        node->max_cap = max(node->left->max_cap, node->right->max_cap);
        node->min_cap = min(node->left->min_cap, node->right->min_cap);
    }
    
    int query_tree(SegmentTreeNode* node, int l, int r, int x) {
        if (node->r < l || node->l > r || node->max_cap < x) {
            return -1;
        }
        if (node->l == node->r) {
            if (node->max_cap >= x) {
                return node->l;
            } else {
                return -1;
            }
        }
        int res_left = query_tree(node->left, l, r, x);
        if (res_left != -1) {
            return res_left;
        }
        return query_tree(node->right, l, r, x);
    }
    
public:
    SegmentTree(vector<int> baskets) : baskets(baskets), n(baskets.size()) {
        if (n == 0) return;
        root = build_tree(0, n - 1);
    }
    
    void update(int idx, int val) {
        if (n == 0) return;
        update_tree(root, idx, val);
    }
    
    int query(int x) {
        if (n == 0) return -1;
        return query_tree(root, 0, n - 1, x);
    }
    
private:
    SegmentTreeNode* root;
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int> fruits, vector<int> baskets) {
        int n = fruits.size();
        int m = baskets.size();
        if (n == 0 || m == 0) return n;
        
        SegmentTree st(baskets);
        int unplaced = 0;
        for (int qty : fruits) {
            if (qty == 0) continue;
            int idx = st.query(qty);
            if (idx == -1) {
                unplaced++;
            } else {
                st.update(idx, 0);
            }
        }
        return unplaced;
    }
};