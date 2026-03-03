/*
 Problem: 757. Pyramid Transition Matrix
 Language: cpp
 Runtime: 43 ms (87.93%)
 Memory: 15.6 MB (58.75%)
 Tags: Hash Table, String, Backtracking, Bit Manipulation
*/
class Solution {
    int allow[7][7] = {};
    unordered_set<string> memo;

    bool buildNextRow(const string& row, int idx, string& next) {
        if (idx == next.size()) {
            return dfs(next);
        }

        int a = row[idx] - 'A';
        int b = row[idx + 1] - 'A';
        int mask = allow[a][b];
        if (mask == 0) return false;

        while (mask) {
            int c = __builtin_ctz(mask);
            mask &= (mask - 1);

            next[idx] = char('A' + c);
            if (buildNextRow(row, idx + 1, next)) return true;
        }
        return false;
    }

    bool dfs(const string& row) {
        if (row.size() == 1) return true;
        if (memo.count(row)) return false;

        string next(row.size() - 1, ' ');
        if (buildNextRow(row, 0, next)) return true;

        memo.insert(row);
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) {
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            int c = s[2] - 'A';
            allow[a][b] |= (1 << c);
        }
        return dfs(bottom);
    }
};
