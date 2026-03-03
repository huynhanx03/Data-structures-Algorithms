/*
 Problem: 36. Valid Sudoku
 Language: cpp
 Runtime: 4 ms (41.89%)
 Memory: 22 MB (65.95%)
 Tags: Array, Hash Table, Matrix
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; ++i) {
            vector<bool> check(10, false);

            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '.')
                    continue;

                int v = board[i][j] - '0';

                if (check[v])
                    return false;

                check[v] = true;
            }
        }

        for (int i = 0; i < m; ++i) {
            vector<bool> check(10, false);

            for (int j = 0; j < n; ++j) {
                if (board[j][i] == '.')
                    continue;

                int v = board[j][i] - '0';

                if (check[v])
                    return false;

                check[v] = true;
            }
        }

        for (int vi = 0; vi < 3; ++vi) {
            for (int vj = 0; vj < 3; ++vj) {
                vector<bool> check(10, false);

                for (int i = vi * 3; i < vi * 3 + 3; ++i)
                    for (int j = vj * 3; j < vj * 3 + 3; ++j) {
                        if (board[i][j] == '.')
                            continue;

                        int v = board[i][j] - '0';

                        if (check[v])
                            return false;

                        check[v] = true;
                    }
            }
        }

        return true;
    }
};