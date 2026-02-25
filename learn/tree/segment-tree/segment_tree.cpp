#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;

    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        int leftNode = 2 * node;
        int rightNode = 2 * node + 1;
        build(arr, leftNode, start, mid);
        build(arr, rightNode, mid + 1, end);
        tree[node] = tree[leftNode] + tree[rightNode]; // Adjust for max/min if needed
    }

    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        int leftNode = 2 * node;
        int rightNode = 2 * node + 1;
        if (start <= idx && idx <= mid) {
            update(leftNode, start, mid, idx, val);
        } else {
            update(rightNode, mid + 1, end, idx, val);
        }
        tree[node] = tree[leftNode] + tree[rightNode];
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; // Adjust identity value for max/min if needed
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftNode = 2 * node;
        int rightNode = 2 * node + 1;
        long long p1 = query(leftNode, start, mid, l, r);
        long long p2 = query(rightNode, mid + 1, end, l, r);
        return p1 + p2;
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
