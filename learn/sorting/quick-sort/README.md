# Quick Sort

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
Quick Sort is a Divide and Conquer algorithm. The core idea is to pick an element as a pivot and partition the given array around the picked pivot. All elements smaller than the pivot are placed before it, and all elements greater are placed after it.

## Approach
1. Pick a pivot element (e.g., the last element of the array).
2. Partition the array such that all elements smaller than the pivot come before it, and all elements greater come after it. The pivot is then placed in its correct sorted position.
3. Recursively apply the same logic to the subarray before the pivot and the subarray after the pivot.

## Complexity
- Time complexity:
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n^2) (occurs when the array is already sorted or reverse sorted and the pivot is the largest or smallest element)

- Space complexity:
  - O(log n) average for the recursion stack, up to O(n) in the worst case.
