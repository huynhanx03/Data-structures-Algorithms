# Merge Sort

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
Merge Sort is a Divide and Conquer algorithm. The idea is to divide the input array into two halves, recursively sort both halves, and then merge the two sorted halves back into a single sorted array.

## Approach
1. **Divide:** Find the midpoint to divide the array into two halves: `left` and `right`.
2. **Conquer:** Recursively sort the left half and right half.
3. **Combine (Merge):** Merge the two sorted halves into a single sorted array. This is done by comparing the elements of both halves and picking the smaller one sequentially.

## Complexity
- Time complexity:
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)

- Space complexity:
  - O(n), as it requires temporary arrays to hold the halves during the merge step.
