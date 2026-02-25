# Max Heap

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A Max Heap is a specialized complete binary tree tailored to ensure that every parent node strictly holds a value greater than or equal to its associated child nodes. This establishes the absolute maximum geometric value residing unconditionally atop the root element, empowering instantaneous queries. Typically, it is simulated ingeniously flattening the 2D tree seamlessly into a 1D sequential Array structure for optimum memory locality and raw speed.

## Approach
1. **Underlying Storage:** Flattened completely within a dynamic `vector`. Any parent index `i` implicitly dictates its left child naturally exists at `2 * i + 1` and its right child at `2 * i + 2`.
2. **Insertion (`heapifyUp`):** Append the freshly introduced element pushing to the extreme bottom (end of array). Immediately trigger an upward recursive swap bubbling sequence (`heapifyUp`) forcefully swapping the new node with its parent routinely until equilibrium is restored if it happens to be strictly larger than its father.
3. **Deletion (`deleteMax` / `heapifyDown`):** Overwrite the topmost root component abruptly with the very last bottom-most leaf node within the array, then prune that leaf node completely. To correct the blatantly broken root condition, drill downwards (`heapifyDown`), swapping the impostor root continuously against whichever of its two children embodies the bigger chunk, rippling downward recursively restoring structure.

## Complexity
- Time complexity:
  - Extract/Peek Maximum: O(1)
  - Insertion & Deletion: O(log N) mathematically constrained by the intrinsic strictly restricted depth of the complete tree hierarchy.

- Space complexity:
  - O(N) physically housing the comprehensive collection of distinct node counts inside the host internal array boundary.
