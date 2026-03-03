/*
 Problem: 1039. Find the Town Judge
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 65.3 MB (50.40%)
 Tags: Array, Hash Table, Graph Theory
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n + 5);
        vector<bool> check(n + 5, true);

        if (n == 1) return 1;

        for (int i = 0; i < trust.size(); ++i) {
            int a = trust[i][0];
            int b = trust[i][1];

            check[a] = false;
            ++cnt[b];
        }

        
        for (int i = 0; i <= n; ++i) {
            if (cnt[i] == n- 1 && check[i]) return i;
        }

        return -1;
    }
}; 