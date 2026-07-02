/*
 Problem: 2001. Jump Game VII
 Language: cpp
 Runtime: 8 ms (67.70%)
 Memory: 24.7 MB (44.35%)
 Tags: String, Dynamic Programming, Sliding Window, Prefix Sum
*/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        int farthest = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) {
                return true;
            }

            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0' && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }

            farthest = max(farthest, end);
        }

        return false;
    }
};