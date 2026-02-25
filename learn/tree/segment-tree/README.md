# Segment Tree

[VI](./README_VI.md) | [EN](./README.md)

A Segment Tree is a versatile data structure used to store information about intervals (or segments) of an array. It allows querying which of the stored segments contain a given point, or answering range queries (like sum, minimum, maximum) efficiently over an array, while also supporting updates to the array elements.

## Intuition

Imagine you have an array and need to perform two types of operations frequently: update the value of an element and find the sum (or min/max) of elements in a specific range. A naive approach would take $O(1)$ for updates but $O(N)$ for queries (using the raw array) or $O(N)$ for updates and $O(1)$ for queries (using a prefix sum array). A Segment Tree balances these operations, achieving $O(\log N)$ for both.

It does this by building a binary tree where the leaf nodes represent individual array elements, and each internal node represents a segment (a range of elements) and stores the aggregated value (e.g., sum, min, max) of its children segments.

## Approach

-   **Structure:** It is a binary tree where each node represents an interval `[l, r]`.
    -   The root represents the entire array `[0, N-1]`.
    -   If a node represents `[l, r]` and $l \neq r$, its left child represents `[l, mid]` and its right child represents `[mid+1, r]`, where $mid = (l+r)/2$.
    -   Leaf nodes represent a single element `[i, i]`.
    -   It is often implemented using an array of size $4N$ to ensure enough space for a complete binary tree mapping.
-   **Build (`build(node, start, end)`):** Recursively divide the array until you reach individual elements (leaves). Then, as the recursion unwinds, compute the value of the parent node based on its children (e.g., `tree[node] = tree[left] + tree[right]`).
-   **Point Update (`update(node, start, end, idx, val)`):** To update an element at index `idx`, traverse down the tree to the leaf representing `[idx, idx]`, update its value, and then update all its ancestors on the path back to the root.
-   **Range Query (`query(node, start, end, l, r)`):** To query a range `[l, r]`:
    -   If the current node's range `[start, end]` is completely completely outside `[l, r]`, return an identity value (e.g., 0 for sum, $\infty$ for min).
    -   If the current node's range `[start, end]` is completely inside `[l, r]`, return the node's value.
    -   Otherwise, the range partially overlaps. Recursively query the left and right children and combine their results.

## Complexity Property

-   **Time Complexity:**
    -   Build: $O(N)$ because it visits each node in the tree exactly once.
    -   Point Update: $O(\log N)$ as it traverses the height of the tree.
    -   Range Query: $O(\log N)$ as it visits at most 4 nodes per level of the tree.
-   **Space Complexity:** $O(N)$. Specifically, an array of size $4N$ is typically used to represent the tree.
