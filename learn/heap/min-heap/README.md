# Min Heap

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A Min Heap is identically structured mirroring physically a Max Heap functionally backwards. It mandates a rigorous operational requirement guaranteeing that every single originating parent node houses strictly exclusively a value mathematically definitively lesser than or equally tying its direct succeeding child nodes. Consequently, the minimum foundational component safely crowns the hierarchy atop perfectly at the absolute structural root array index `0`.

## Approach
1. **Underlying Array Storage:** Employs a fundamental 1D `vector` array representation seamlessly plotting a dense binary tree explicitly utilizing index arithmetic bounds.
2. **Insertion (`heapifyUp`):** Sequentially append the newly supplied figure towards the outermost far right slot (back of array). Fire off a comparative subroutine filtering dynamically ascending the hierarchical ladder swapping relentlessly contrasting node parameters logically unless validating the smaller condition optimally satisfied.
3. **Deletion (`deleteMin` / `heapifyDown`):** Extract and annihilate the prized miniature artifact residing at index 0. Re-bridge the gap directly plugging manually the terminal leaf index value natively upward onto the void, severing subsequently the orphaned duplicated end leaf. Push logically plummeting downward rearranging node positions validating minimizing trait consistently via bubbling smallest children progressively upwards.

## Complexity
- Time complexity:
  - Read Top Minimum: O(1)
  - Inserting entities & Deleting constraints: O(log N) mathematically driven identically scaling tree depth properties.

- Space complexity:
  - O(N) physically bounded strictly containing variables internal to array constraints exclusively.
