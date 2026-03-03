/*
 Problem: 4018. Minimum Moves to Balance Circular Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 194 MB (40.64%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();

        long long sum = 0;
        for (const auto& x : balance) {
            sum += x;
        }

        if (sum < 0) return -1;

        int start = 0;

        for (int i = 0; i < n; ++i) {
            if (balance[i] < 0) {
                start = i;
                break;
            }
        }

        long long res = 0;
        long long cur = balance[start];

        int l = (start - 1 + n) % n;
        int r = (start + 1) % n;
        long long cnt = 1;
        
        while (cur < 0) {
            long long move = min(abs(cur), 1LL * balance[l]);
            cur += move;
            res += move * cnt;
    
            if (cur >= 0) break;

            if (l != r) {
                move = min(abs(cur), 1LL * balance[r]);
                cur += move;
                res += move * cnt;
            }
            
            l = (l - 1 + n) % n;
            r = (r + 1) % n;
            ++cnt;
        }

        return res;
    }
};