/*
 Problem: 1428. Jump Game III
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 35.5 MB (73.30%)
 Tags: Array, Depth-First Search, Breadth-First Search
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0) {
                return true;
            }

            int right = i + arr[i];
            int left = i - arr[i];

            if (right >= 0 && right < n && !visited[right]) {
                visited[right] = true;
                q.push(right);
            }

            if (left >= 0 && left < n && !visited[left]) {
                visited[left] = true;
                q.push(left);
            }
        }

        return false;
    }
};