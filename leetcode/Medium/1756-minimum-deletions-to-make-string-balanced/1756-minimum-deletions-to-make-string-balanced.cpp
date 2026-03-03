/*
 Problem: 1756. Minimum Deletions to Make String Balanced
 Language: cpp
 Runtime: 43 ms (24.95%)
 Memory: 55 MB (20.91%)
 Tags: String, Dynamic Programming, Stack
*/
class Solution {
public:
    int minimumDeletions(string S) {
        int N = S.length();
        
        // Prefix sum for 'B's: prefixB[i] = number of 'B's in S[0..i]
        std::vector<int> prefixB(N + 1, 0);
        for (int i = 0; i < N; i++) {
            prefixB[i + 1] = prefixB[i] + (S[i] == 'b' ? 1 : 0);
        }
        
        // Suffix sum for 'A's: suffixA[i] = number of 'A's in S[i..N-1]
        std::vector<int> suffixA(N + 1, 0);
        for (int i = N - 1; i >= 0; i--) {
            suffixA[i] = suffixA[i + 1] + (S[i] == 'a' ? 1 : 0);
        }
        
        int minDeletions = N; 
        for (int i = 0; i <= N; i++) {
            // Split at position i:
            // - Left of i (positions 0 to i-1): keep 'A's, delete 'B's
            // - Right of i (positions i to N-1): keep 'B's, delete 'A's
            int deletions = prefixB[i] + suffixA[i];
            minDeletions = std::min(minDeletions, deletions);
        }
        
        return minDeletions;
    }
};