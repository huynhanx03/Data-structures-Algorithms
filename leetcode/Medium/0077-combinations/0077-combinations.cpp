/*
 Problem: 77. Combinations
 Language: cpp
 Runtime: 327 ms (5.03%)
 Memory: 157.9 MB (6.63%)
 Tags: Backtracking
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> check;

    void backtrack(int idx, int&n, int& k, vector<int> takes) {
        if (idx == k) {
            ans.push_back(takes);
            return;
        }

        int sz = takes.size();

        for (int i = sz > 0 ? takes[sz - 1] + 1 : 1; i <= n; ++i) {
            if (check[i]) continue;
            
            check[i] = 1;
            takes.push_back(i);
            
            backtrack(idx + 1, n, k, takes);
            
            check[i] = 0;
            takes.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        check.resize(n + 5, 0);
        backtrack(0, n, k, vector<int>());

        return ans;      
    }
};