# Hash Table (Chaining)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
Hashing provides a mechanism to drastically reduce array search time by translating keys directly into specific index locations using a mathematical Hash Function. However, multiple keys inevitably map to the same exact slot creating a "collision". The Separate Chaining technique gracefully resolves this by allowing each slot in the hash table to act as an independent linked list (or dynamic array), chaining colliding elements together infinitely.

## Approach
1. **Underlying Structure:** The table physically consists of an Array of Linked Lists. Let `M` be the table capacity.
2. **Hash Function:** Converts raw keys into an array index classically using modulo arithmetic: `key % M`.
3. **Insertion:** Hash the key to find the respective pocket index. Proceed to push the new element directly into the linked list hanging off that exact index bucket.
4. **Search / Deletion:** Hash the key to discover the assigned bucket index. Linearly iterate entirely through the linked list contained internally exclusively within that bucket to locate, verify, or surgically remove the target element.

## Complexity
- Time complexity:
  - Average Case (Search, Insert, Delete): O(1) supposing keys miraculously scatter evenly.
  - Worst Case: O(N) if every single key disastrously clashes hashing into precisely the exact same bucket, degrading the structure entirely into one massive linked list.

- Space complexity:
  - O(N + M) spatially accommodating `M` buckets permanently plus dynamic allocation supporting exactly `N` unique inserted entities.
