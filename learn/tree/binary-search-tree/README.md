# Binary Search Tree

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A Binary Search Tree (BST) is a node-based binary tree data structure that enforces a strict ordering rule: the left subtree of a node contains only nodes with keys lesser than the node's key, and the right subtree contains only nodes with keys greater than the node's key. This property enables lightning-fast lookups, inserts, and deletes relative to standard trees.

## Approach
1. **Search:** Compare search target with the current node. If it matches, you found it. If target is smaller, strictly navigate left. If greater, navigate right.
2. **Insertion:** Follow the identical search pattern to locate the precise sterile empty slot obeying the constraint rule, linking the new item flawlessly to the parent wrapper organically.
3. **Deletion:** Find the target node. There are three possibilities:
   - Node has no children: Just snip it out.
   - Node has one child: Splice bypassing the node to connect its child straight to its parent.
   - Node has two children: Identify the minimal value in its right subtree (the successor), overwrite the target node with that value, and perform deletion recursively resolving the successor placeholder.

## Complexity
- Time complexity:
  - Search, Insertion, Deletion: O(log N) average, dipping plummeting down directly to O(N) worst-case if the items were inserted practically already ordered building a linear slope.

- Space complexity:
  - O(N) to store nodes. Recursion stacks could stack up dynamically stretching up to O(N).
