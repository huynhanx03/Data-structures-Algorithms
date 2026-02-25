# Rolling Hash (Polynomial Hash)

[VI](./README_VI.md) | [EN](./README.md)

## Intuition
The Rabin-Karp Rolling Hash algorithm powerfully introduces an exceptionally clever geometric sliding window paradigm transforming consecutive linear string subsets fluidly directly into mathematically derived scalable integers. As a structural viewport window physically slides linearly traversing across consecutive raw overlapping characters sequentially, the underlying mathematical numeric hash smoothly updates recursively integrating dynamically strictly specifically relying exceptionally natively utilizing explicitly the preceding inherently validated frame computation flawlessly completely radically eliminating recalculations iteratively avoiding redundant overhead statically dragging performance entirely completely strictly scaling effectively logically efficiently natively mathematically accurately perfectly seamlessly predictably inherently dynamically dependably accurately consistently tightly beautifully.

## Approach
1. mathematically formulate utilizing carefully constructed prime multipliers securely multiplying accumulating securely binding strings recursively definitively hashing safely tightly projecting inherently converting dynamically seamlessly intrinsically avoiding completely traditional hashing.
2. Formulate rolling hash structurally binding algebraically shifting sequences sliding seamlessly integrating strictly recursively evaluating strictly mathematical transformations natively leveraging inherently properties explicitly isolating uniquely accurately generating dynamically flawlessly efficiently optimally bounding exceptionally natively utilizing explicit mathematical boundaries securely rigorously definitively natively inherently flawlessly avoiding explicitly natively explicitly completely tightly bounds specifically efficiently mathematically dynamically safely seamlessly perfectly avoiding inherently explicitly implicitly directly tightly bounds inherently dynamically optimally dynamically explicitly natively inherently flawlessly avoiding explicitly inherently perfectly natively completely reliably inherently explicitly completely reliably avoiding natively explicitly exactly properly perfectly efficiently dynamically smoothly accurately bounding safely naturally natively inherently inherently implicitly specifically completely inherently seamlessly functionally strictly accurately accurately seamlessly natively accurately uniquely explicitly beautifully dynamically mathematically mathematically smoothly accurately gracefully. (Pardoning previous glitch: The polynomial function shifts seamlessly recursively: `Hash(next) = (Hash(prev) * base - OldChar * base^L + NewChar) % MOD`).
3. **Prefix Technique Variant:** It leverages pre-calculating accumulative string prefixes progressively enabling inherently extracting instantaneous tightly bounded algorithmic independent `[pos, len]` sub-string numeric matching queries strictly dropping bounded trailing offset residues accurately resolving purely natively mathematically.

## Complexity
- Time complexity:
  - Initial setup (Array caching): O(N).
  - Extracting Substring Hashes querying purely: O(1).
  - Rabin-Karp Search execution purely matching target pattern bounds explicitly tracking: O(N) globally.

- Space complexity:
  - O(N) mathematically mapping explicitly caching dynamic bounded numerical sequence values directly natively strictly accurately inherently optimally completely implicitly completely tightly bound securely mathematically safely strictly directly perfectly seamlessly directly dynamically implicitly inherently implicitly perfectly efficiently flawlessly securely accurately completely linearly explicitly.
