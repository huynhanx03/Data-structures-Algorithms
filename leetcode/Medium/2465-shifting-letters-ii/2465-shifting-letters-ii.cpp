/*
 Problem: 2465. Shifting Letters II
 Language: cpp
 Runtime: 4 ms (72.72%)
 Memory: 97.8 MB (73.80%)
 Tags: Array, String, Prefix Sum
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size(), cnt = 0;

        vector<int> v(n + 5, 0);

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            v[start] += direction == 1 ? 1 : -1;
            v[end + 1] += direction == 1 ? -1 : 1;
        }

        for (int i = 0; i < n; ++i) {
            cnt += v[i];

            char c = (char) ((((s[i] - 'a' + cnt) % 26) + 26) % 26 + 'a');

            s[i] = c;
        }

        return s;
    }
};