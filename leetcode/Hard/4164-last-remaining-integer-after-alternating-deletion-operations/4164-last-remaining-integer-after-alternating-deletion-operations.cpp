/*
 Problem: 4164. Last Remaining Integer After Alternating Deletion Operations
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.2 MB (8.32%)
 Tags: Math, Recursion
*/
class Solution {
public:
    long long lastInteger(long long n) {
        long long head = 1;
        long long step = 1;
        long long remaining = n;
        bool left = true;

        while (remaining > 1) {
            if (!left) {
                if (remaining % 2 == 0) head += step;
            }

            remaining = remaining - remaining / 2;
            step *= 2;
            left = !left;
        }

        return head;
    }
};