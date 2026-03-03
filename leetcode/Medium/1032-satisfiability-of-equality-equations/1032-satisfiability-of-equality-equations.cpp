/*
 Problem: 1032. Satisfiability of Equality Equations
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14.8 MB (99.32%)
 Tags: Array, String, Union-Find, Graph Theory
*/
class Solution {
private:
    int u[26];

    int find(int x) {
        if (x != u[x]) u[x] = find(u[x]);
        return u[x];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        // dsu
        for (int i = 0; i < 26; ++i) {
            u[i] = i;
        }

        // group
        for (const auto& equation : equations) {
            if (equation[1] == '=') {
                u[find(equation[0] - 'a')] = find(equation[3] - 'a');
            }
        }

        // check
        for (const auto& equation : equations) {
            if (equation[1] == '!' && find(equation[0] - 'a') == find(equation[3] - 'a'))
                return false;
        }

        return true;
    }
};