# Circular Linked List

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A circular linked list is a variation of a linked list where all nodes are connected to form a circle. There is no `NULL` at the end. Instead, the last node's `next` pointer points back to the first node.

## Approach
1. **Structure:** Only maintaining a `tail` pointer is sufficient. Because `tail->next` is the head, we have direct O(1) access to both ends of the list.
2. **Insertion:**
   - At Head: Insert the new node after the `tail`. The new node becomes the new head (`tail->next = newNode`).
   - At Tail: Insert the new node after the `tail`, then update the `tail` pointer itself to be the new node.
3. **Traversal:** Using a `do-while` loop is highly effective since we must loop until the current pointer circles back and hits the starting node.

## Complexity
- Time complexity:
  - Access/Search: O(n)
  - Insertion at Head: O(1)
  - Insertion at Tail: O(1) (given the maintained `tail` pointer)
  - Deletion: O(n)

- Space complexity:
  - O(n) for storing nodes.
