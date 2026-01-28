# Intuition
The problem asks for the minimum cost to travel from the top-left $(0, 0)$ to the bottom-right $(n-1, m-1)$ in a grid. We have two ways to move:
1.  **Adjacent Move:** Move **Right** or **Down**. The cost is the value of the destination cell.
2.  **Teleportation:** Jump from the current cell $(x, y)$ to **any** cell $(x', y')$ in the grid, provided that $grid[x'][y'] \le grid[x][y]$. This move has a **cost of 0** and can be used at most $k$ times.

Since all costs (cell values) are non-negative, this is a shortest path problem that can be solved using **Dijkstra's Algorithm**. However, we need to track the number of teleportations used in our state.

# Approach
### 1. State Definition
Define `dist[tp][pos]` as the minimum cost to reach a cell at 1D index `pos` (where `pos = x * m + y`) having used exactly `tp` teleportations.
- `0 <= tp <= k`
- `0 <= pos < n * m`

### 2. Transitions
From a state `(cost, pos, tp)`:

-   **Adjacent Moves:**
    -   Try moving to `(x, y + 1)` and `(x + 1, y)`.
    -   New cost: `nc = cost + grid[next_x][next_y]`.
    -   Update `dist[tp][next_pos] = min(dist[tp][next_pos], nc)`.
-   **Teleportation:**
    -   If `tp < k`, we can jump to any cell `v` where `grid[v] <= grid[x][y]`.
    -   Cost remains `cost` (0 cost jump).
    -   Update `dist[tp + 1][v] = min(dist[tp + 1][v], cost)`.

### 3. Optimization for Teleportation
A naive teleportation step would take $O(N \cdot M)$ for each state, leading to $O(K \cdot (NM)^2)$, which is too slow. We optimize this as follows:
1.  **Pre-sort Cells:** Store all cells as pairs of `{value, pos}` and sort them by value.
2.  **Two-Pointer / Persistent Progress:** For each teleportation level `tp`, we maintain a pointer `ptr[tp]`.
3.  **Active Threshold:** When in a state with `tp` teleportations at a cell with value $V$, we only need to consider jumping to cells $v$ in the sorted list where $grid[v] \le V$.
4.  **Avoid Redundancy:** Once a cell $v$ has been "reached" via teleportation at level `tp + 1`, we don't need to process it as a teleportation destination again for the same level. We use a `used[tp][v]` array to track this. Since our Dijkstra processes states in increasing order of cost, the first time we teleport to `v` at level `tp + 1`, it will be with the minimum possible cost.

# Complexity
- **Time Complexity:** $O(K \cdot NM \log(NM) + NM \log(NM))$.
- **Space Complexity:** $O(K \cdot NM)$

# Code
```cpp []
class Solution {
public:
    const int INF = 1e9;

    struct Node {
        int cost, pos, tp;
        bool operator>(const Node& o) const {
            return cost > o.cost;
        }
    };

    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int tot = n * m;

        vector<pair<int,int>> cells;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cells.push_back({grid[i][j], i * m + j});
        sort(cells.begin(), cells.end());

        vector<vector<int>> dist(k + 1, vector<int>(tot, INF));
        vector<vector<bool>> used(k + 1, vector<bool>(tot, false));
        vector<int> ptr(k + 1, 0);

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [cost, pos, tp] = pq.top();
            pq.pop();
            
            if (cost != dist[tp][pos]) continue;

            int x = pos / m, y = pos % m;

            if (y + 1 < m) {
                int v = pos + 1;
                int nc = cost + grid[x][y + 1];
                if (nc < dist[tp][v]) {
                    dist[tp][v] = nc;
                    pq.push({nc, v, tp});
                }
            }

            if (x + 1 < n) {
                int v = pos + m;
                int nc = cost + grid[x + 1][y];
                if (nc < dist[tp][v]) {
                    dist[tp][v] = nc;
                    pq.push({nc, v, tp});
                }
            }

            if (tp < k) {
                while (ptr[tp] < tot && cells[ptr[tp]].first <= grid[x][y]) {
                    int v = cells[ptr[tp]].second;
                    if (!used[tp][v]) {
                        used[tp][v] = true;
                        if (cost < dist[tp + 1][v]) {
                            dist[tp + 1][v] = cost;
                            pq.push({cost, v, tp + 1});
                        }
                    }
                    ++ptr[tp];
                }
            }
        }

        int ans = INF;
        for (int i = 0; i <= k; ++i)
            ans = min(ans, dist[i][tot - 1]);

        return ans == INF ? -1 : ans;
    }
};
```