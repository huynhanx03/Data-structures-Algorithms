# Hash Table (Linear Probing)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
When a hashing collision strictly occurs—meaning a newly processed key hashes physically mapping directly onto an index slot already claimed by another occupant—Linear Probing dictates fundamentally to search sequentially stepping forwards strictly one slot horizontally at a time internally until an empty, completely unoccupied array gap is organically discovered safely allowing settlement.

## Approach
1. **Core Backbone:** Maintain a flat standard array without dynamically branching structures (no linked list dependencies). Keep a parallel synchronized tracking system identically sized mapping booleans definitively locking slot occupancy states.
2. **Insertion:** Compute original hashing index. If the landing bucket securely remains empty, comfortably drop the item there. If an annoying collision strikes, sequentially navigate the sequence wrapping tightly via modulo bound operations linearly `(index + 1) % capacity` probing frantically inspecting onward until an isolated free chamber opens up logically resolving placement.
3. **Searching:** Hash uniquely locating the starting coordinate. Walk progressively evaluating consecutive rooms actively. The search completely halts abruptly only once encountering exactly mathematically the target matching perfectly, spotting genuinely a physically empty spot conclusively failing execution, or spinning redundantly completing a full cyclical scan proving pure nonexistence.
4. **Deletion:** Search procedurally extracting the item strictly purging the content deliberately masking substituting leaving an empty void flag.

## Complexity
- Time complexity:
  - Average Case (Search, Insert, Delete): O(1) mathematically reliant exceptionally upon light sparse load bounds avoiding clustering chunks closely tight heavily tightly compacted blocks natively known severely degrading velocity.
  - Worst Case: O(N) if extreme catastrophic clustering fundamentally spirals uncontrollably dictating dragging iterative looping exhaustive scans touching brutally entirely across the dense array completely sequentially.

- Space complexity:
  - O(M) strictly strictly mapping explicitly the completely static absolute table capacity memory chunk. Constraints strictly tightly bound preventing stretching past arrays capacity linearly strictly inherently bounding internal volume.
