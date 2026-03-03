/*
 Problem: 3779. Eat Pizzas!
 Language: cpp
 Runtime: 66 ms (90.57%)
 Memory: 180.1 MB (58.96%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
       sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int cnt = n / 4;
        long long sum = 0;
        int l = 0, r = n - 1;

        for (int i = 0; i < (cnt + 1) / 2; ++i) {
            sum += pizzas[r--];
            l += 3;
        }

        cnt -= (cnt + 1) / 2;

        for (int i = 0; i < cnt; ++i) {
            sum += pizzas[r - 1];
            r -= 2;
        }

        return sum;
    }
};