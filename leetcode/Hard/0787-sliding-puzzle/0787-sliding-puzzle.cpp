/*
 Problem: 787. Sliding Puzzle
 Language: cpp
 Runtime: 2 ms (98.94%)
 Memory: 11.9 MB (6.70%)
 Tags: Array, Dynamic Programming, Backtracking, Breadth-First Search, Memoization, Matrix
*/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        for (auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }

        vector<vector<int>> neighbors = {
            {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}
        };

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == target) {
                return steps;
            }

            int zeroPos = current.find('0');
            for (int neighbor : neighbors[zeroPos]) {
                string next = current;
                swap(next[zeroPos], next[neighbor]);
                if (!visited.count(next)) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }
        return -1;
    }
};