/*
 Problem: 4047. Longest Balanced Subarray II
 Language: cpp
 Runtime: 356 ms (92.33%)
 Memory: 137.6 MB (92.08%)
 Tags: Array, Hash Table, Divide and Conquer, Segment Tree, Prefix Sum
*/
struct Node {
    int mn, mx, lz;
};

class Solution {
    vector<Node> tree;
    int n;

    void push(int v) {
        if (tree[v].lz) {
            tree[2 * v].mn += tree[v].lz;
            tree[2 * v].mx += tree[v].lz;
            tree[2 * v].lz += tree[v].lz;
            
            tree[2 * v + 1].mn += tree[v].lz;
            tree[2 * v + 1].mx += tree[v].lz;
            tree[2 * v + 1].lz += tree[v].lz;
            
            tree[v].lz = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[v].mn += add;
            tree[v].mx += add;
            tree[v].lz += add;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), add);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
            tree[v].mn = min(tree[2 * v].mn, tree[2 * v + 1].mn);
            tree[v].mx = max(tree[2 * v].mx, tree[2 * v + 1].mx);
        }
    }

    int findFirst(int v, int tl, int tr, int l, int r) {
        if (l > r || tree[v].mn > 0 || tree[v].mx < 0) return -1;
        if (tl == tr) return tl;
        push(v);
        int tm = (tl + tr) / 2;
        int res = findFirst(2 * v, tl, tm, l, min(r, tm));
        if (res != -1) return res;
        return findFirst(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, {0, 0, 0});
        
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        
        vector<int> last(vals.size(), -1);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int w = (val % 2 == 0) ? 1 : -1;
            int idx = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
            
            update(1, 0, n - 1, last[idx] + 1, i, w);
            last[idx] = i;
            
            int l = findFirst(1, 0, n - 1, 0, i);
            if (l != -1) {
                ans = max(ans, i - l + 1);
            }
        }
        return ans;
    }
};