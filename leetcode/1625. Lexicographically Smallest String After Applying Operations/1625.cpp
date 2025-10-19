class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> vis;
        string ans = s;

        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            ans = min(ans, cur);

            // Operation 1: add 'a' to all odd indices
            string t = cur;
            for (int i = 1; i < t.size(); i += 2)
                t[i] = (t[i] - '0' + a) % 10 + '0';
            if (!vis.count(t)) {
                vis.insert(t);
                q.push(t);
            }

            // Operation 2: rotate right by b positions
            string r =
                cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!vis.count(r)) {
                vis.insert(r);
                q.push(r);
            }
        }

        return ans;
    }
};