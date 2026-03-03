/*
 Problem: 4147. Minimum Cost to Acquire Required Items
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.3 MB (30.75%)
 Tags: Math, Greedy
*/
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long op1 = n1 * c1 + n2 * c2;

        long long op2 = max(n1, n2) * cb;

        long long op3;

        if (n1 > n2) {
            op3 = n2 * cb + (n1 - n2) * c1;
        } else {
            op3 = n1 * cb + (n2 - n1) * c2;
        }
        
        return max(0ll, min({op1, op2, op3}));
    }
};