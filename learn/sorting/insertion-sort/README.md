# Insertion Sort

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
The idea is similar to sorting playing cards in your hands. We split the array into a sorted and an unsorted part. Values from the unsorted part are picked and placed in their correct position in the sorted part.

## Approach
1. Iterate from the second element `i = 1` to `n-1`.
2. Compare the current element `key` to its predecessors in the sorted subarray `[0, i-1]`.
3. Shift all elements in the sorted subarray that are greater than `key` one position to the right.
4. Insert the `key` into its correct position.

## Complexity
- Time complexity:
  - Best Case: O(n) (when the array is already sorted)
  - Average Case: O(n^2)
  - Worst Case: O(n^2)

- Space complexity:
  - O(1), as it sorts the array in-place.
