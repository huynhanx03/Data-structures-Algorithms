/*
 Problem: 2766. Find the Prefix Common Array of Two Arrays
 Language: cpp
 Runtime: 51 ms (5.09%)
 Memory: 94.2 MB (5.09%)
 Tags: Array, Hash Table, Bit Manipulation
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> commonElements;
        vector<int> result(A.size(), 0);
        unordered_map<int, int> countA, countB;

        for (int i = 0; i < A.size(); ++i) {
            countA[A[i]]++;
            countB[B[i]]++;

            if (countA[A[i]] > 0 && countB[A[i]] > 0) {
                commonElements.insert(A[i]);
            }
            if (countA[B[i]] > 0 && countB[B[i]] > 0) {
                commonElements.insert(B[i]);
            }

            result[i] = commonElements.size();
        }

        return result;
    }
};
