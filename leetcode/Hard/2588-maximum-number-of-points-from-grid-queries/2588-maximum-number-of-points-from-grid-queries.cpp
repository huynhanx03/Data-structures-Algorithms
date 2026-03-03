/*
 Problem: 2588. Maximum Number of Points From Grid Queries
 Language: cpp
 Runtime: 86 ms (86.26%)
 Memory: 40 MB (100.00%)
 Tags: Array, Two Pointers, Breadth-First Search, Union-Find, Sorting, Heap (Priority Queue), Matrix
*/
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> answer(queries.size());
        vector<pair<int, int>> indexedQueries;

        for (int i = 0; i < queries.size(); ++i)
            indexedQueries.emplace_back(queries[i], i);

        sort(indexedQueries.begin(), indexedQueries.end());

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dd[5] = {0, -1, 0, 1, 0};
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int points = 0;

        for (auto& [query, idx] : indexedQueries) {
            while (!pq.empty() && pq.top().first < query) {
                auto [value, cell] = pq.top();
                pq.pop();
                int x = cell.first, y = cell.second;

                ++points;

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dd[i], ny = y + dd[i + 1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }

            answer[idx] = points;
        }

        return answer;
    }
};