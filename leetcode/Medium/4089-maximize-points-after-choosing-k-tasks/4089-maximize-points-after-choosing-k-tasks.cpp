/*
 Problem: 4089. Maximize Points After Choosing K Tasks
 Language: cpp
 Runtime: 48 ms (72.47%)
 Memory: 213.8 MB (75.56%)
 Tags: Array, Greedy, Sorting, Heap (Priority Queue)
*/
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<long long> gain(n);
        long long base = 0;
        
        for (int i = 0; i < n; ++i) {
            base += technique2[i];
            gain[i] = (long long) technique1[i] - technique2[i];
        }

        sort(gain.begin(), gain.end(), greater<long long>());
        for (int i = 0; i < k; ++i) {
            base += gain[i];
        }

        for (int i = k; i < n; ++i) {
            if (gain[i] > 0) base += gain[i];
        }

        return base;
    }
};