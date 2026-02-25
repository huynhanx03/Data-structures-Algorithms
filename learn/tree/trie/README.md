# Trie (Prefix Tree)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
A Trie is an advanced tree data structure engineered meticulously for exceptionally fast retrieval of strings mapping characters recursively. Each string injected decomposes inherently directly down corresponding node-levels letter by letter, rendering the Trie the ultimate weapon primarily driving auto-complete and predictive spelling functionalities.

## Approach
1. Construct nodes housing a hash map (`unordered_map`) explicitly tethering local alphabetic key characters physically to adjoining child sub-nodes. Add a boolean flag tracking strictly word completions denoting valid terminators.
2. **Insertion:** Dissect the string characters looping iteratively. If an absent key drops, spawn dynamic nodes extending outward down branches progressively trailing each letter sequentially up to wrapping logic ending flagged TRUE globally.
3. **Searching:** Navigate paths mapping sequentially tracking individual given inputs character sequence. A flawless discovery demands reaching string depletion precisely dropping simultaneously down landing overlapping heavily onto an implicitly flagged terminal boolean node marker confirming legitimate boundaries.
4. **Prefix Tracing:** Run identical routines mapping down character sequences without dictating absolute termination validation enforcement inherently confirming simple branch existence validity.

## Complexity
- Time complexity:
  - Inserting, Seeking exact string, Seeking prefixes universally lock fundamentally hitting exactly: O(L) where L represents uniquely solely the maximum length measured of whatever input word itself.

- Space complexity:
  - O(N * L * Alphabet Size) sprawling dynamically representing N total aggregate input entities stored securely. Heavily exhaustive spatially on physical RAM bounds natively without deliberate pathway compressions.
