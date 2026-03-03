/*
 Problem: 289. Game of Life
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.7 MB (34.05%)
 Tags: Array, Matrix, Simulation
*/
class Solution {

private:
int directions[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

public : void
         gameOfLife(vector<vector<int>> & board) {
        int n = board.size(), m = board[0].size();

        vector<vector<int>> curr = board;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int cnt = 0;

                for (int k = 0; k < 8; ++k) {
                    int ni = i + directions[k][0];
                    int nj = j + directions[k][1];

                    if (ni >= n || ni < 0 || nj >= m || nj < 0)
                        continue;

                    cnt += curr[ni][nj];
                }

                if (board[i][j] == 1) {
                    if (cnt > 3 || cnt < 2)
                        board[i][j] = 0;
                } else {
                    if (cnt == 3)
                        board[i][j] = 1;
                }
            }
    };
};