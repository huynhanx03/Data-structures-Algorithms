/*
 Problem: 4095. Number of Balanced Integers in a Range
 Language: cpp
 Runtime: 95 ms (67.82%)
 Memory: 9.9 MB (72.61%)
 Tags: Dynamic Programming
*/
class Solution {
private:
    long long memo[20][2][400][2][2];
    string S;
    const int OFFSET = 200;

    long long dp(int idx, bool tight, int sum, bool isStart, bool isOdd) {
        if (idx == S.size()) {
            return !isStart && sum == OFFSET;
        }

        if (memo[idx][tight][sum][isStart][isOdd] != -1) {
            return memo[idx][tight][sum][isStart][isOdd];
        }

        long long ans = 0;
        int limit = tight ? (S[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; ++digit) {
            bool nextTight = tight && (digit == limit);

            if (isStart) {
                if (digit == 0) {
                    ans += dp(idx + 1, nextTight, sum, true, true);
                } else {
                    ans += dp(idx + 1, nextTight, sum + digit, false, false);
                }
            } else {
                int nextSum = isOdd ? sum + digit : sum - digit;
                ans += dp(idx + 1, nextTight, nextSum, false, !isOdd);
            }
        }

        memo[idx][tight][sum][isStart][isOdd] = ans;
        return ans;
    }

    long long count(string s) {
        S = s;
        memset(memo, -1, sizeof(memo));
        return dp(0, true, OFFSET, true, true);
    }
public:
    long long countBalanced(long long low, long long high) {
        return count(to_string(high)) - count(to_string(low - 1));
    }
};