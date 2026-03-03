/*
 Problem: 310. Minimum Height Trees
 Language: cpp
 Runtime: 105 ms (9.63%)
 Memory: 92.3 MB (5.06%)
 Tags: Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        // Build the adjacency list
        unordered_map<int, unordered_set<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        // Initialize leaves
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) {
                leaves.push(i);
            }
        }
        
        // Trim the leaves until we reach the centroids
        while (n > 2) {
            int leavesCount = leaves.size();
            n -= leavesCount;
            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (const int& neighbor : adj[leaf]) {
                    adj[neighbor].erase(leaf);
                    if (adj[neighbor].size() == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        
        // Collect the remaining nodes
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};