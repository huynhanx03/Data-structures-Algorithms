# Queue (Linked List Implementation)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
By utilizing a linked list to implement a queue, you remove the fixed capacity constraints naturally occurring in an Array-based approach. We can endlessly insert elements without dealing with pointers wrapping around circles or running out of memory bounds manually.

## Approach
1. Use a standard Singly Linked List keeping two independent pointer references: `front` representing the queue's exit (head) and `rear` representing the queue's entry (tail).
2. **Enqueue:** Attach new data seamlessly at the `rear`. Connect the existing `rear`'s next pointer dynamically to this node, migrating `rear` subsequently to point directly at the newly inserted object. If inserting into an unpopulated structure, both `front` and `rear` share the identical sole object.
3. **Dequeue:** Unhook and dump the exact first element assigned to `front`, and bump the existing `front` to point up sequentially across to the following chained counterpart. If there are logically zero members left upon deletion, enforce mapping `rear` cleanly back to null.
4. **Peek:** Reveal precisely what hides stored in the specific component held tightly active over at the `front` reference tag.

## Complexity
- Time complexity:
  - Enqueue, Dequeue, Peek, isEmpty check operations strictly function in instantaneous fixed logic times: O(1)

- Space complexity:
  - O(N) expanding or reducing inherently proportionate strictly correlating directly to whatever count sequence items dynamically co-exist actively stored inside the framework.
