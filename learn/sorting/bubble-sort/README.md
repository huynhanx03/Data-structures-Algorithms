# Bubble Sort

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
The idea is to repeatedly step through the list, compare adjacent elements, and swap them if they are in the wrong order. The pass through the list is repeated until the list is sorted. The largest elements "bubble" to the top (end of the array) first.

## Approach
1. Use an outer loop to iterate through the array `n-1` times.
2. Use an inner loop to compare adjacent elements from index `0` to `n-i-1`.
3. If the current element is greater than the next element, swap them.
4. After each iteration of the outer loop, the largest unsorted element is placed in its correct position at the end of the array.

## Complexity
- Time complexity:
  - Best Case: O(n) (if implemented with an early exit flag, otherwise O(n^2))
  - Average Case: O(n^2)
  - Worst Case: O(n^2)

- Space complexity:
  - O(1), as it sorts the array in-place.
