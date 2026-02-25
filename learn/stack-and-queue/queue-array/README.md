# Queue (Array Implementation)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A Queue is a linear data structure working on FIFO (First In First Out) ideology. Think of people lining up waiting for service; the one who joined the queue first gets to leave first. The array implementation uses a cyclic (circular) mechanism to reuse space efficiently when `front` and `rear` pointers are drifting towards the end of the array.

## Approach
1. Initialize a dynamically allocated array and distinct tracking variables (`front`, `rear`, `capacity`, `size`).
2. **Enqueue:** Push value into the queue at the modulo-adjusted position: `rear = (rear + 1) % capacity`. Increment `size`. Ensure the queue isn't full.
3. **Dequeue:** Extract value from the queue using `front` index. Recompute `front` position via `front = (front + 1) % capacity`. Decrement `size`. Check if it's empty first.
4. The modulo operator `%` guarantees that when the pointer reaches the final element of the array, it automatically wraps around to the beginning, treating the linear continuous array structure strictly like a circle loop.

## Complexity
- Time complexity:
  - Enqueue, Dequeue, Peek: O(1)

- Space complexity:
  - O(N) where N is the fixed static `capacity` constraint.
