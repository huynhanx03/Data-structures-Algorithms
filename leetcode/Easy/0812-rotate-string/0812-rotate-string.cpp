/*
 Problem: 812. Rotate String
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.2 MB (5.60%)
 Tags: String, String Matching
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        int n = s.size();
        string t = s + s;

        using ull = unsigned long long;
        const ull base = 131;

        auto buildHash = [&](const string& str) {
            vector<ull> h(str.size() + 1, 0);
            for (int i = 0; i < (int)str.size(); ++i) {
                h[i + 1] = h[i] * base + str[i];
            }
            return h;
        };

        vector<ull> pw(2 * n + 1, 1);
        for (int i = 1; i <= 2 * n; ++i) {
            pw[i] = pw[i - 1] * base;
        }

        auto getHash = [&](const vector<ull>& h, int l, int r) {
            return h[r] - h[l] * pw[r - l];
        };

        auto ht = buildHash(t);
        auto hg = buildHash(goal);

        ull goalHash = getHash(hg, 0, n);

        for (int i = 0; i + n <= 2 * n; ++i) {
            if (getHash(ht, i, i + n) == goalHash) {
                if (t.substr(i, n) == goal) return true;
            }
        }

        return false;
    }
};