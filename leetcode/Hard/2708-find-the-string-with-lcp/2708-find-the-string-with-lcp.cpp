/*
 Problem: 2708. Find the String with LCP
 Language: cpp
 Runtime: 79 ms (7.23%)
 Memory: 77.2 MB (54.22%)
 Tags: Array, String, Dynamic Programming, Greedy, Union-Find, Matrix
*/
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        auto unite = [&](int a, int b) {
            a = find(a), b = find(b);
            if (a != b) parent[b] = a;
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (lcp[i][j] > 0) unite(i, j);
            }
        }
        
        string res(n, '#');
        unordered_map<int, char> mp;
        char cur = 'a';
        
        for (int i = 0; i < n; ++i) {
            int p = find(i);
            if (!mp.count(p)) {
                if (cur > 'z') return "";
                mp[p] = cur++;
            }
            res[i] = mp[p];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int expected = 0;
                if (res[i] == res[j]) {
                    if (i + 1 < n && j + 1 < n)
                        expected = lcp[i + 1][j + 1] + 1;
                    else
                        expected = 1;
                }
                if (lcp[i][j] != expected) return "";
            }
        }
        
        return res;
    }
};