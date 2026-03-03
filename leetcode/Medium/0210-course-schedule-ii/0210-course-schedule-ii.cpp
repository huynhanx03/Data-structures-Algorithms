/*
 Problem: 210. Course Schedule II
 Language: cpp
 Runtime: 8 ms (23.96%)
 Memory: 17.9 MB (94.45%)
 Tags: Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> order;

        // Build the graph and in-degree array
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        // Find all nodes with zero in-degree
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the nodes
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int neighbor : graph[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check for cycles
        if (order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
};
