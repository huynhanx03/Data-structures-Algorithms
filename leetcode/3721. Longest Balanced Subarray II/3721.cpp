struct Node {
    int mn, mx, lz;
};

struct SegmentTree {
    int n;
    vector<Node> tree;

    SegmentTree(int n) : n(n), tree(4 * n) {}

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
        if (l > r)
            return;
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

    int get(int v, int tl, int tr, int l, int r) {
        if (l > r || tree[v].mn > 0 || tree[v].mx < 0)
            return -1;
        if (tl == tr)
            return tl;
        push(v);
        int tm = (tl + tr) / 2;
        int res = get(2 * v, tl, tm, l, min(r, tm));
        if (res != -1)
            return res;
        return get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> last(vals.size(), -1);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int w = (val % 2 == 0) ? 1 : -1;
            int idx = lower_bound(vals.begin(), vals.end(), val) - vals.begin();

            st.update(1, 0, n - 1, last[idx] + 1, i, w);
            last[idx] = i;

            int l = st.get(1, 0, n - 1, 0, i);
            if (l != -1) {
                ans = max(ans, i - l + 1);
            }
        }
        return ans;
    }
};