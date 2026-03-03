/*
 Problem: 407. Trapping Rain Water II
 Language: cpp
 Runtime: 131 ms (8.10%)
 Memory: 40.9 MB (5.45%)
 Tags: Array, Breadth-First Search, Heap (Priority Queue), Matrix
*/
class Solution {
public:
    struct Cell {
        int height;
        int row;
        int col;
        bool operator<(const Cell& other) const {
            return height > other.height;
        }
    };

    int trapRainWater(vector<vector<int>>& heights) {
        int vol = 0;
        const int M = heights.size(), N = heights[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        priority_queue<Cell> min_heap;
        
        for(int i = 0; i < N; i++) {
            min_heap.push({heights[0][i], 0, i});
            min_heap.push({heights[M-1][i], M-1, i});
            visited[0][i] = true;
            visited[M-1][i] = true;
        }
        
        for(int i = 0; i < M; i++) {
            min_heap.push({heights[i][0], i, 0});
            min_heap.push({heights[i][N-1], i, N-1});
            visited[i][0] = true;
            visited[i][N-1] = true;
        }
            
        while(!min_heap.empty()) {
            Cell cell = min_heap.top();
            min_heap.pop();
            
            for(auto dir: directions) {
                int r = cell.row + dir[0], c = cell.col + dir[1];
                if(r >= 0 && r < M && c >= 0 && c < N && !visited[r][c]) {
                    visited[r][c] = true;
                    if(heights[r][c] < cell.height)
                        vol += cell.height - heights[r][c];
                    min_heap.push({max(cell.height, heights[r][c]), r, c});
                }
            }
        }
        return vol;
    }
};
