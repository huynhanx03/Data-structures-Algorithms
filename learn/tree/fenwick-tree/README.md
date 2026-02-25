# Fenwick Tree (Binary Indexed Tree)

[VI](./README_VI.md) | [EN](./README.md)

A Fenwick Tree, also known as a Binary Indexed Tree (BIT), is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers. It provides $O(\log N)$ time complexity for both operations.

## Intuition

A Fenwick Tree combines the concepts of partial sum arrays and interval trees. Instead of storing the sum of elements from $0$ to $i$, it stores the sum of elements from $i - lowbit(i) + 1$ to $i$. The function $lowbit(i)$ extracts the lowest set bit of $i$, which effectively divides the array into a hierarchy of intervals. This clever arrangement allows both updates and queries to traverse at most $\log N$ nodes.

## Approach

-   **Structure:** An array `bits` of size $N+1$ (1-indexed). The element at index `i` contains the sum of elements in the range $[i - lowbit(i) + 1, i]$.
-   **`lowbit(i)`:** Calculated using bitwise operations: `i & -i`. In two's complement, `-i` is `~i + 1`. This isolates the least significant bit that is set to 1.
-   **Point Update (`update(i, x)`):** To add `x` to the $i$-th element, we must update all intervals in the `bits` array that contain the $i$-th element. We increment `i` by `lowbit(i)` repeatedly until $i$ exceeds the array size.
-   **Prefix Query (`query(i)`):** To get the sum from $1$ to $i$, we sum the current interval `bits[i]` and then move to the preceding non-overlapping interval by subtracting `lowbit(i)` from `i` repeatedly until $i$ becomes $0$.
-   **Range Query (`queryRange(l, r)`):** To get the sum from $l$ to $r$, we calculate the difference of two prefix queries: `query(r) - query(l - 1)`.

## Complexity Property

-   **Time Complexity:**
    -   Build: $O(N \log N)$ by updating each element. (Can be optimized to $O(N)$).
    -   Point Update: $O(\log N)$
    -   Range Query: $O(\log N)$
-   **Space Complexity:** $O(N)$ for the `bits` array.
