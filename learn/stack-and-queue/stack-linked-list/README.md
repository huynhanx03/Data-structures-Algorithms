# Stack (Linked List Implementation)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
Unlike an array-based stack which has a fixed capacity, a linked list stack can grow dynamically without the risk of overflow. The "top" of the stack is represented by the `head` pointer of a singly linked list.

## Approach
1. **Push:** Allocate a new node, point its `next` to the current `top`, and then move the `top` pointer to this new node. This mimics `insertAtHead` in a standard singly linked list.
2. **Pop:** The data from the node currently at `top` is extracted. The `top` pointer is then shifted to `top->next`, and the old memory block is deleted. Mimicking `deleteHead`.
3. **Peek:** Return the data residing in the `top` node.

## Complexity
- Time complexity:
  - Push, Pop, Peek, isEmpty: O(1) (No traversal is needed since everything happens at the head node)

- Space complexity:
  - O(N) where N is the current number of elements logically held inside the stack. Dynamic memory ensures no space is wasted.
