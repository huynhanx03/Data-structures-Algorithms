# Binary Tree

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A Binary Tree is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child. It represents non-linear relationships and forms the foundation for more advanced data structures like BST and heaps.

## Approach
1. **Structure:** Every element is wrapped into a Node containing `data`, a `left` pointer, and a `right` pointer.
2. **Insertion:** Start from the `root`. If empty, make the new node the root. Otherwise, traverse downwards (typically deciding left or right based on simple logic like comparison, making it akin to a naive BST building process here) until an empty sibling slot is found to attach the new element.
3. **Deletion:** Deletion in a basic binary tree entails locating the node and replacing it, usually with the rightmost or leftmost valid element, ensuring that all sub-children pointers are reattached without dropping branches.

## Complexity
- Time complexity:
  - Search, Insertion, Deletion: O(N) in the absolute worst-case unbalanced tree (a straight line like a linked list), O(log N) for a balanced tree.

- Space complexity:
  - O(N) representing node storage. Depth recursion dictates the execution stack space.
