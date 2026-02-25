# Stack (Array Implementation)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A Stack is a linear data structure that follows the LIFO (Last In First Out) principle. Think of it like a stack of plates: you can only add or remove from the very top. Implementing it with an array requires pre-defining a maximum capacity and keeping an index tracking the "top" of the stack.

## Approach
1. Initialize a dynamically allocated array and set the `top` index to `-1` to indicate an empty stack.
2. **Push:** Increment the `top` index and place the new value in the array at that index. Check for overflow before doing so.
3. **Pop:** Retrieve the value at the `top` index, then decrement the `top` index. Check for underflow first.
4. **Peek:** Simply observe the element at the `top` index without modifying `top`.

## Complexity
- Time complexity:
  - Push, Pop, Peek, isEmpty: O(1)

- Space complexity:
  - O(N) where N is the `capacity` initialized for the array. Memory is pre-allocated regardless of actual usage.
