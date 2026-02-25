# Doubly Linked List

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A doubly linked list extends the singly linked list by adding a `prev` pointer to each node. This allows traversal in both directions (forward and backward) and makes operations like deleting a specific node easier if you already have a pointer to it.

## Approach
1. **Node Structure:** Each node stores the `data`, a `next` pointer, and a `prev` pointer.
2. **Insertion:** 
   - When adding a new node, its `prev` pointer must connect back to the preceding node, and its `next` pointer refers to the succeeding node.
   - For `insertAtHead`, the old head's `prev` becomes the new node.
3. **Deletion:** Bypassing a node involves two pointer updates: the previous node's `next` points to the next node, and the next node's `prev` points to the previous node. Thus safely detaching the target node so it can be deleted.

## Complexity
- Time complexity:
  - Access/Search: O(n)
  - Insertion at Head: O(1)
  - Insertion at Tail: O(n) (or O(1) if a tail pointer is maintained)
  - Deletion: O(n) (to find the node), O(1) (to delete it once found)

- Space complexity:
  - O(n), requiring slightly more memory than a singly linked list due to the extra `prev` pointer per node.
