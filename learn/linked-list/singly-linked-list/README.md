# Singly Linked List

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A singly linked list is a linear data structure where elements are not stored in contiguous memory locations. Instead, each element (node) contains its data and a pointer/reference linking to the next node in the sequence.

## Approach
1. **Node Structure:** Each node stores the `data` and a `next` pointer.
2. **Head Pointer:** The list itself only needs to keep track of the `head` pointer (the first node).
3. **Insertion:** 
   - At Head: Create a new node, point its `next` to the current head, and update `head`.
   - At Tail: Traverse to the last node (where `next` is null) and point it to the new node.
4. **Deletion:** Traverse to find the node just before the one to be deleted, then update its `next` pointer to skip the targeted node. Free the targeted node's memory.

## Complexity
- Time complexity:
  - Access/Search: O(n)
  - Insertion at Head: O(1)
  - Insertion at Tail: O(n) (since we must traverse from head to tail to append, without a tail pointer)
  - Deletion: O(n)

- Space complexity:
  - O(n) for storing `n` nodes.
