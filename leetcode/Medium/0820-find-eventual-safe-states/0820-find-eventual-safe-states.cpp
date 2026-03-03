/*
 Problem: 820. Find Eventual Safe States
 Language: cpp
 Runtime: 54 ms (30.85%)
 Memory: 65.9 MB (56.67%)
 Tags: Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0);
        vector<vector<int>> reverseGraph(n);
        
        // Build the reverse graph and calculate outdegrees
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                reverseGraph[j].push_back(i);
                outdegree[i]++;
            }
        }
        
        // Collect all terminal nodes
        vector<int> safeNodes;
        for (int i = 0; i < n; ++i) {
            if (outdegree[i] == 0) {
                safeNodes.push_back(i);
            }
        }
        
        // Process the terminal nodes
        for (int i = 0; i < safeNodes.size(); ++i) {
            int node = safeNodes[i];
            for (int neighbor : reverseGraph[node]) {
                outdegree[neighbor]--;
                if (outdegree[neighbor] == 0) {
                    safeNodes.push_back(neighbor);
                }
            }
        }
        
        // Sort the safe nodes
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
