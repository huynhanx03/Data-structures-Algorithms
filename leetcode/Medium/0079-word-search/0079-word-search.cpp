/*
 Problem: 79. Word Search
 Language: cpp
 Runtime: 982 ms (6.98%)
 Memory: 11.4 MB (47.14%)
 Tags: Array, String, Backtracking, Depth-First Search, Matrix
*/
class Solution {
public:
    int dd[5] = {-1, 0, 1, 0, -1};

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int sz = word.size();

        if (n * m < sz)
            return false;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == word[0]) {
                    bool check = search(board, word, i, j, 0, n, m, sz);
                    if (check)
                        return true;
                }

        return false;
    }

    bool search(vector<vector<char>>& board, string word, int row, int col, int idx, int n, int m, int sz) {
        if (idx == sz)
            return true;

        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[idx])
            return false;  
    
        board[row][col] = '*';

        for (int i = 0; i < 4; ++i) {
            bool check = search(board, word, row + dd[i], col + dd[i + 1], idx + 1, n, m, sz);
            if (check)
                return true;
        }

        board[row][col] = word[idx];
        return false;
    }
};