/*
 Problem: 2220. Find All Possible Recipes from Given Supplies
 Language: cpp
 Runtime: 112 ms (59.97%)
 Memory: 165.4 MB (24.24%)
 Tags: Array, Hash Table, String, Graph Theory, Topological Sort
*/
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());

        for (int i = 0; i < recipes.size(); i++) {
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
                inDegree[recipes[i]]++;
            }
        }

        queue<string> q;
        for (const string& supply : supplies) {
            q.push(supply);
        }

        vector<string> result;

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            for (const string& neighbor : graph[item]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                    result.push_back(neighbor);
                }
            }
        }

        return result;
    }
};