/*
 Problem: 2766. Find the Prefix Common Array of Two Arrays
 Language: cpp
 Runtime: 15 ms (24.05%)
 Memory: 94.4 MB (6.65%)
 Tags: Array, Hash Table, Bit Manipulation
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> cnt;
        vector<int> res(A.size(), 0);
        unordered_map<int, int> cntA, cntB;

        for (int i = 0; i < A.size(); ++i) {
            cntA[A[i]]++;
            cntB[B[i]]++;

            if (cntA[A[i]] > 0 && cntB[A[i]] > 0) {
                cnt.insert(A[i]);
            }
            if (cntA[B[i]] > 0 && cntB[B[i]] > 0) {
                cnt.insert(B[i]);
            }

            res[i] = cnt.size();
        }

        return res;
    }
};
