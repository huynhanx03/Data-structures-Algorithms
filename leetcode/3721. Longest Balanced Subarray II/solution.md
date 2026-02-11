# Intuition
The problem asks for the longest subarray where the count of distinct even numbers equals the count of distinct odd numbers. We can maintain a difference `diff = (distinct evens) - (distinct odds)` for all possible starting positions `j` as we iterate through the array with end position `i`. If for stored start index `j`, the current difference is 0, it means the subarray `nums[j...i]` is balanced.

When we encounter a number `x` at index `i`, it only contributes to the distinct count for subarrays starting after its previous occurrence. We can use a Segment Tree to update the difference for ranges of starting positions and query for the leftmost position with value 0.

# Approach
We use a **Segment Tree** to maintain the `diff` values for all start indices `j` ($0 \le j \le i$). The tree supports:
1.  **Range Update**: When we see `nums[i]`, we update the range `[last_pos[nums[i]] + 1, i]` by adding $+1$ (if even) or $-1$ (if odd).
2.  **Query**: Find the leftmost index `j` in `[0, i]` such that the value is 0. We maintain minimum (`mn`) and maximum (`mx`) values in each node to quickly check if 0 exists in a range.

# Complexity

-   **Time complexity:** $O(N \log N)$

-   **Space complexity:** $O(N)$

# Code
```cpp []
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
```