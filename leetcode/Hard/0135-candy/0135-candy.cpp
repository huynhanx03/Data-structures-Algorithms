/*
 Problem: 135. Candy
 Language: cpp
 Runtime: 14 ms (6.29%)
 Memory: 20.1 MB (100.00%)
 Tags: Array, Greedy
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> ans(n, 1);
int sum = 0;
        for (int i = 0; i < n; ++i) {
            // - 1
            if (i) {
                if (ratings[i] > ratings[i - 1])
                ans[i] = ans[i - 1] + 1;
            }

            // + 1
            if (i < n - 1) {
                if (ratings[i] > ratings[i + 1])
                    ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            // - 1
            if (i) {
                if (ratings[i] > ratings[i - 1])
                ans[i] = ans[i - 1] + 1;
            }

            // + 1
            if (i < n - 1) {
                if (ratings[i] > ratings[i + 1])
                    ans[i] = max(ans[i], ans[i + 1] + 1);
            }

            sum += ans[i];
        }

        return sum;
    }
};