/*
 Problem: 3748. Sort Matrix by Diagonals
 Language: cpp
 Runtime: 21 ms (9.05%)
 Memory: 47.3 MB (5.60%)
 Tags: Array, Sorting, Matrix
*/
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                mp[i - j].push_back(grid[i][j]);
            }
        }

        map<int, int> mpos;

        for (auto &it : mp)
        {
            mpos[it.first] = 0;
            if (it.first < 0)
            {
                sort(it.second.begin(), it.second.end());
            }
            else
            {
                sort(it.second.rbegin(), it.second.rend());
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                grid[i][j] = mp[i - j][mpos[i - j]];
                ++mpos[i - j];
            }
        }
        return grid;
    }
};