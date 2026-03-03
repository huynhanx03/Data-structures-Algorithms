/*
 Problem: 3809. Properties Graph
 Language: cpp
 Runtime: 135 ms (56.47%)
 Memory: 119.9 MB (35.29%)
 Tags: Array, Hash Table, Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
*/
class Solution {
private:
    int intersect(const vector<int>& a, const vector<int>& b) {
        vector<int> count(101, 0);
        int common = 0;

        for (const int& num : a) {
            count[num] = 1;
        }

        for (const int& num : b) {
            if (count[num] == 1) {
                ++common;
                count[num] = 0;
            }
        }

        return common;
    }

public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(properties[i], properties[j]) >= k) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++components;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        return components;
    }
};
