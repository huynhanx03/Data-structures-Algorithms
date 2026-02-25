# Selection Sort

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
The idea is to divide the array into two parts: a sorted subarray and an unsorted subarray. Initially, the sorted subarray is empty. We repeatedly find the minimum element from the unsorted subarray and put it at the end of the sorted subarray.

## Approach
1. Iterate over the array from `0` to `n-1`. This is the boundary between the sorted and unsorted parts.
2. Find the index of the minimum element in the unsorted subarray `[i, n-1]`.
3. Swap the minimum element with the first element of the unsorted subarray (at index `i`).
4. Repeat this process until the entire array is sorted.

## Complexity
- Time complexity:
  - Best Case: O(n^2)
  - Average Case: O(n^2)
  - Worst Case: O(n^2) (Always scans the remaining array to find the minimum)

- Space complexity:
  - O(1), as it sorts the array in-place.
