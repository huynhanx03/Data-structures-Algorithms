/*
 Problem: 1447. Jump Game IV
 Language: cpp
 Runtime: 97 ms (39.48%)
 Memory: 80.3 MB (35.84%)
 Tags: Array, Hash Table, Breadth-First Search
*/
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int step = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                if (i == n - 1) return step;

                vector<int>& next = mp[arr[i]];

                next.push_back(i - 1);
                next.push_back(i + 1);

                for (const auto& j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }

                next.clear();
            }

            ++step;
        }

        return -1;
    }
};