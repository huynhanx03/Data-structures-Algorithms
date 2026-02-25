# Binary Search

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
Binary search is used to efficiently find a target value within a sorted array. Instead of searching linearly from the beginning, it repeatedly halves the search space by comparing the target with the middle element.

## Approach
1. Initialize two pointers, `low` at the start (0) and `high` at the end (`n-1`) of the array.
2. While `low` <= `high`, calculate the middle index `mid`.
3. If the middle element matches the target, return its index.
4. If the middle element is greater than the target, restrict the search to the left half (`high = mid - 1`).
5. If the middle element is smaller than the target, restrict the search to the right half (`low = mid + 1`).
6. Return `-1` if the loop ends and the element is not found.

## Complexity
- Time complexity:
  - Best Case: O(1) (when the target is precisely at the middle on the first check)
  - Average Case: O(log n)
  - Worst Case: O(log n)

- Space complexity:
  - O(1) for the iterative approach.
