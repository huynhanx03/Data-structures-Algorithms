/*
 Problem: 2793. Count the Number of Complete Components
 Language: cpp
 Runtime: 37 ms (74.49%)
 Memory: 128.1 MB (79.54%)
 Tags: Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
*/
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int nodeCount = 0;
                int edgeCount = 0;
                dfs(i, graph, visited, nodeCount, edgeCount);
                if (edgeCount / 2 == nodeCount * (nodeCount - 1) / 2) {
                    ++completeCount;
                }
            }
        }

        return completeCount;
    }

private:
    void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited,
            int& nodeCount, int& edgeCount) {
        visited[node] = true;
        ++nodeCount;
        edgeCount += graph[node].size();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, nodeCount, edgeCount);
            }
        }
    }
};