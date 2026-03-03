/*
 Problem: 3744. Minimum Operations to Make Array Elements Zero
 Language: cpp
 Runtime: 12 ms (72.14%)
 Memory: 183.4 MB (47.21%)
 Tags: Array, Math, Bit Manipulation
*/
class Solution {
public:
    long long compute_s(int x) {
        long long s = 0;
        while (x > 0) {
            x /= 4;
            s++;
        }
        return s;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long total_operations = 0;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            long long sum_s = 0;

            for (int k = 1;; ++k) {
                long long low = 1ULL << (2 * (k - 1));  // 4^(k-1)
                long long high = (1ULL << (2 * k)) - 1; // 4^k - 1
                if (low > r) {
                    break;
                }
                
                long long current_low = max(static_cast<long long>(l), low);
                long long current_high = min(static_cast<long long>(r), high);
                
                if (current_low > current_high) {
                    continue;
                }
                
                long long count = current_high - current_low + 1;
                sum_s += count * k;
            }

            long long max_s = compute_s(r);
            long long operations = max(static_cast<long long>((sum_s + 1) / 2), max_s);
            total_operations += operations;
        }
        return total_operations;
    }
};