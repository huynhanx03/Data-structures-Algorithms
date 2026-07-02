/*
 Problem: 3435. Block Placement Queries
 Language: cpp
 Runtime: 381 ms (69.07%)
 Memory: 341.1 MB (74.22%)
 Tags: Array, Binary Search, Binary Indexed Tree, Segment Tree, Ordered Set
*/
class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> tree;

        SegmentTree(int size) {
            n = size;
            tree.assign(4 * n + 5, 0);
        }

        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                tree[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (idx <= mid)
                update(node * 2, l, mid, idx, val);
            else
                update(node * 2 + 1, mid + 1, r, idx, val);

            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return 0;

            if (ql <= l && r <= qr) {
                return tree[node];
            }

            int mid = (l + r) / 2;

            return max(
                query(node * 2, l, mid, ql, qr),
                query(node * 2 + 1, mid + 1, r, ql, qr)
            );
        }

        void update(int idx, int val) {
            update(1, 0, n, idx, val);
        }

        int query(int l, int r) {
            if (l > r) return 0;
            return query(1, 0, n, l, r);
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxX = 0;

        for (auto& q : queries) {
            maxX = max(maxX, q[1]);
        }

        SegmentTree seg(maxX + 2);

        set<int> obstacles;
        obstacles.insert(0);

        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto it = obstacles.lower_bound(x);
                int right = (it == obstacles.end()) ? maxX + 1 : *it;
                int left = *prev(it);

                obstacles.insert(x);

                seg.update(x, x - left);

                if (right <= maxX) {
                    seg.update(right, right - x);
                }
            } 
            else {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                int left = *prev(it);

                int maxGapBeforeX = seg.query(0, x);
                int tailGap = x - left;

                int best = max(maxGapBeforeX, tailGap);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};