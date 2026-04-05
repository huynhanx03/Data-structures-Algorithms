/*
 Problem: 210. Course Schedule II
 Language: cpp
 Runtime: 2 ms (76.53%)
 Memory: 18.3 MB (70.91%)
 Tags: Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> d(numCourses, 0);
        vector<int> res;

        for (const auto& pre : prerequisites) {
            g[pre[1]].push_back(pre[0]);
            ++d[pre[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (d[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);

            for (const auto& y : g[x]) {
                --d[y];
                if (d[y] == 0) {
                    q.push(y);
                }
            }
        }

        if (res.size() == numCourses) {
            return res;
        } else {
            return {};
        }
    }
};
