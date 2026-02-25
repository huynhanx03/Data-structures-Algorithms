# AVL Tree

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A binary search tree's performance severely plummets to O(N) if keys are sequentially sorted leading into it. To mitigate this flaw, self-balancing architectures were proposed. AVL trees track a parameter called "height" dynamically across operations, triggering a localized rotation restoring pure symmetry whenever unbalances surface violently skewed.

## Approach
1. It maintains exactly logic identical inherited from a naive strictly constructed Binary Search Tree.
2. **Heights & Balance Factor:** Attach a `height` property bound physically inside each specific node object. Compute localized balance defined primarily by: `height(left) - height(right)`.
3. **Rotations:** When absolute balance falls aggressively beyond bounds (> 1 or < -1), engage precise corrective spatial twisting flips.
   - Left-Left skew -> Rotate logically towards Right.
   - Right-Right skew -> Rotate naturally Left.
   - Left-Right skew -> Pre-rotate internally Left pushing it down to Left-Left, then subsequently rotate Right globally.
   - Right-Left skew -> Pre-rotate Right isolating Right-Right, followed swiftly with overarching Left rotation.

## Complexity
- Time complexity:
  - Search, Insertion, Deletion essentially locked in strictly mathematically bound tight parameters: O(log N) unequivocally.

- Space complexity:
  - O(N) spatial mapping. Call stack spans exactly proportional tightly to O(log N).
