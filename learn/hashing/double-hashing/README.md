# Double Hashing (String Hashing)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
String hashing simplifies exceptionally complex heavy string comparison tasks directly into extremely fast localized lightweight numeric equality checks. To minimize and entirely thwart horrific mathematical collision probabilities fundamentally threatening basic single modulo polynomial rolling hashes securely, Double Hashing concurrently generates and intricately binds explicitly two exclusively completely independent distinct polynomial hash signatures computed robustly running symmetrically across vastly contrasting unique prime modulo bases inherently practically eliminating mathematically any accidental twin duplicates definitively unconditionally masking string comparisons safely.

## Approach
1. **Foundation Initialization:** Select logically two highly disparate numeric base primes dynamically multiplying progressively generating mathematical powers modulo two massively distant separated prime integers inherently avoiding structural dependencies.
2. **Precompute Prefixes:** Run explicitly iterative sweeps mapping incrementally integrating cumulative consecutive character prefix hashes definitively accumulating sequentially securely locked deep directly into internal parallel 1-Dimensional sequence arrays (O(N) initial effort bounding structural foundation map globally).
3. **Extraction & Slicing (`getHash`):** Evaluating identical string chunks intuitively arbitrarily bounded explicitly starting `[L ... R]` resolves incredibly utilizing clever symmetric arithmetic sliding windows essentially subtracting bounded trailing prefix traces strictly effectively dropping raw chunk remainders immediately extracting independent numeric fingerprints exclusively tracking string configurations matching accurately within pure absolute unadulterated instantaneous instantaneous O(1) mathematically bounded execution constraints unconditionally bypassing completely traditional linear O(K) deep character-by-character native string traversal.

## Complexity
- Time complexity:
  - Blueprint Pre-Computation Construction Phase: O(N) scaling predictably bound sequentially building length dynamically covering exactly absolute `N` length characters.
  - Substring Extraction Comparisons: O(1) mathematical algebraic queries slicing directly fetching perfectly completely regardless intrinsically unbound totally isolating independent lengths naturally dynamically instantly securely locking matching.

- Space complexity:
  - O(N) physically spanning exclusively tightly locked vectors array caches strictly securely logging progressively intermediate prefix numerical fingerprints natively avoiding caching strings entirely physically directly essentially compressing mathematically flawlessly accurately compactly naturally inherently.
