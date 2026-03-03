/*
 Problem: 3764. Maximum Sum With at Most K Elements
 Language: cpp
 Runtime: 187 ms (42.36%)
 Memory: 133.9 MB (11.15%)
 Tags: Array, Greedy, Sorting, Heap (Priority Queue), Matrix
*/
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                pq.emplace(grid[i][j], i);
            }
        }

        vector<int> count(grid.size(), 0); 
        long long sum = 0;

        while (!pq.empty() && k > 0) {
            auto [value, row] = pq.top(); pq.pop();
            if (count[row] < limits[row]) {
                sum += value;
                count[row]++;
                k--;
            }
        }

        return sum;
    }
};
