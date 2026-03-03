/*
 Problem: 945. Snakes and Ladders
 Language: cpp
 Runtime: 4 ms (43.88%)
 Memory: 17.7 MB (31.79%)
 Tags: Array, Breadth-First Search, Matrix
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto getBoardValue = [&](int s) {
            int quot = (s - 1) / n;
            int rem = (s - 1) % n;
            int row = n - 1 - quot;
            int col = (quot % 2 == 0) ? rem : (n - 1 - rem);

            return board[row][col];
        };

        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({1, 0});
        visited.insert(1);

        while (!q.empty()) {
            auto [s, rolls] = q.front();
            
            q.pop();
            
            for (int i = 1; i <= 6; ++i) {
                int next_s = s + i;
                if (next_s > n * n)
                    continue;

                int board_value = getBoardValue(next_s);
                if (board_value != -1) {
                    next_s = board_value;
                }
                
                if (next_s == n * n) {
                    return rolls + 1;
                }
                if (visited.find(next_s) == visited.end()) {
                    visited.insert(next_s);
                    q.push({next_s, rolls + 1});
                }
            }
        }
        return -1;
    }

private:
    void bfs(vector<vector<int>>& board) {}
};