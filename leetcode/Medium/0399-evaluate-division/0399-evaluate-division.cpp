/*
 Problem: 399. Evaluate Division
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 12 MB (60.01%)
 Tags: Array, String, Depth-First Search, Breadth-First Search, Union-Find, Graph Theory, Shortest Path
*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph =
            buildGraph(equations, values);

        vector<double> result(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            result[i] = getPathWeight(queries[i][0], queries[i][1],
                                      unordered_set<string>(), graph);
        }

        return result;
    }

private:
    double
    getPathWeight(const string& start, const string& end,
                  unordered_set<string> visited,
                  unordered_map<string, unordered_map<string, double>>& graph) {

        if (graph.find(start) == graph.end())
            return -1.0;

        if (graph[start].find(end) != graph[start].end())
            return graph[start][end];

        visited.insert(start);

        for (const auto& neighbor : graph[start]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double productWeight =
                    getPathWeight(neighbor.first, end, visited, graph);
                
                if (productWeight != -1.0)
                    return neighbor.second * productWeight;
            }
        }

        return -1.0;
    }

    unordered_map<string, unordered_map<string, double>>
    buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); ++i) {
            const string& u = equations[i][0];
            const string& v = equations[i][1];
            graph[u][v] = values[i];
            graph[v][u] = 1.0 / values[i];
        }

        return graph;
    }
};
