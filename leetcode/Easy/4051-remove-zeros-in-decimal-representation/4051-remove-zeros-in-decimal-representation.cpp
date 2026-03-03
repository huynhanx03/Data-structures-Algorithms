/*
 Problem: 4051. Remove Zeros in Decimal Representation
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.2 MB (43.45%)
 Tags: Math, Simulation
*/
class Solution {
public:
    long long removeZeros(long long n) {
        vector<int> v;
        
        while (n > 0) {
            int rem = n % 10;
            if (rem > 0) v.push_back(rem);
            n /= 10;
        }

        long long ans = 0;

        for (int i = v.size() - 1; i >= 0; --i) {
            ans = ans * 10 + v[i];
        }

        return ans;
    }
};