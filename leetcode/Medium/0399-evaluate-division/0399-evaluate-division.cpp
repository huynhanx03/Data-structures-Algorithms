/*
 Problem: 399. Evaluate Division
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 11.9 MB (58.54%)
 Tags: Array, String, Depth-First Search, Breadth-First Search, Union-Find, Graph Theory, Shortest Path
*/
class Solution {
public:
    bool dfs(string& u, string& t, unordered_map<string, vector<pair<string, double>>>& g,
             unordered_set<string>& vis, double cur, double& ans) {
        if (u == t) {
            ans = cur;
            return true;
        }

        vis.insert(u);

        for (auto& [v, w] : g[u]) {
            if (vis.count(v)) continue;
            if (dfs(v, t, g, vis, cur * w, ans)) return true;
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;

        for (int i = 0; i < equations.size(); ++i) {
            string& a = equations[i][0];
            string& b = equations[i][1];
            double v = values[i];
            g[a].push_back({b, v});
            g[b].push_back({a, 1.0 / v});
        }

        vector<double> res;

        for (auto& q : queries) {
            string& a = q[0];
            string& b = q[1];

            if (!g.count(a) || !g.count(b)) {
                res.push_back(-1.0);
                continue;
            }

            if (a == b) {
                res.push_back(1.0);
                continue;
            }

            unordered_set<string> vis;
            double ans = -1.0;

            if (dfs(a, b, g, vis, 1.0, ans)) res.push_back(ans);
            else res.push_back(-1.0);
        }

        return res;
    }
};