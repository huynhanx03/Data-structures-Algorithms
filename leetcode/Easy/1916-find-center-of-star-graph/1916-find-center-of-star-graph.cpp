/*
 Problem: 1916. Find Center of Star Graph
 Language: cpp
 Runtime: 123 ms (6.17%)
 Memory: 124.7 MB (10.98%)
 Tags: Graph Theory
*/
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> st;
        vector<int> cnt(edges.size() + 5);

        for (const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            st.insert(u);
            st.insert(v);

            ++cnt[u];
            ++cnt[v];
        }

        int n = st.size();

        for (const auto& x : st) {
            if (cnt[x] == n - 1) return x;
        }

        return -1;
    }
};