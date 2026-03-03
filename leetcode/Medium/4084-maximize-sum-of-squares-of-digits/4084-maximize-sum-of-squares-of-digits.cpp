/*
 Problem: 4084. Maximize Sum of Squares of Digits
 Language: cpp
 Runtime: 82 ms (44.48%)
 Memory: 73.3 MB (20.55%)
 Tags: Math, Greedy
*/
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while (sum > 9) {
            sum -= 9;
            ans += '9';
            --num;

            if (num == 0 && sum > 0) return "";
        }

        ans += (char) (sum + '0');
        for (int i = 1; i < num; ++i) ans += '0';
        return ans;
    }
};