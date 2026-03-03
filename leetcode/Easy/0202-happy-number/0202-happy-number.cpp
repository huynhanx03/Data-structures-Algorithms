/*
 Problem: 202. Happy Number
 Language: cpp
 Runtime: 4 ms (4.84%)
 Memory: 7.9 MB (54.57%)
 Tags: Hash Table, Math, Two Pointers
*/
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;

        while (1) {
            int sum = 0;

            while (n > 0) {
                int x = n % 10;

                sum += x * x;

                n /= 10;
            }

            if (sum == 1)
                return 1;

            if (s.find(sum) != s.end())
                return 0;
            
            s.insert(sum);

            n = sum;
        }
    }
};